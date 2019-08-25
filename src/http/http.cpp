#include "http.h"

namespace adpc {
http::http() : curl(nullptr) { curl = curl_easy_init(); }
http::~http() { curl_easy_cleanup(curl); }

/* Auxiliary function that waits on the socket. */
static int wait_on_socket(curl_socket_t sockfd, int for_recv, long timeout_ms) {
  struct timeval tv;
  fd_set infd, outfd, errfd;
  int res;

  tv.tv_sec = timeout_ms / 1000;
  tv.tv_usec = (timeout_ms % 1000) * 1000;

  FD_ZERO(&infd);
  FD_ZERO(&outfd);
  FD_ZERO(&errfd);

  FD_SET(sockfd, &errfd); /* always check for error */

  if (for_recv) {
    FD_SET(sockfd, &infd);
  } else {
    FD_SET(sockfd, &outfd);
  }

  /* select() returns the number of signalled sockets or -1 */
  res = select((int)sockfd + 1, &infd, &outfd, &errfd, &tv);
  return res;
}

bool http::sendAndRecv(void (*func)(char *), const char *request,
                       const size_t buffsize) {

  if (!connectServer()) {
    return false;
  }

  // compose request to http
  func = nullptr;

  // use libcurl to connect the server and send and recevie packages
  sendRequestByCurl(request);
  recvDataByCurl();
  return false;
}

bool http::sendRequestByCurl(const char *request) {
  size_t request_len = strlen(request);
  size_t nsent_total = 0;

  do {
    /* Warning: This example program may loop indefinitely.
     * A production-quality program must define a timeout and exit this loop
     * as soon as the timeout has expired. */
    size_t nsent;

    do {
      nsent = 0;
      res = curl_easy_send(curl, request + nsent_total,
                           request_len - nsent_total, &nsent);
      nsent_total += nsent;

      if (res == CURLE_AGAIN && !wait_on_socket(sockfd, 0, 60000L)) {
        printf("Error: timeout.\n");
        return 1;
      }
    } while (res == CURLE_AGAIN);

    if (res != CURLE_OK) {
      printf("Error: %s\n", curl_easy_strerror(res));
      return 1;
    }

    printf("Sent %" CURL_FORMAT_CURL_OFF_T " bytes.\n", (curl_off_t)nsent);

  } while (nsent_total < request_len);

  return true;
}
bool http::initCurlLib(const char *serverIp) {

  if (curl) {

    /* Do not do the transfer - only connect to host */
    curl_easy_setopt(curl, CURLOPT_CONNECT_ONLY, 1L);
    res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
      printf("Error: %s\n", curl_easy_strerror(res));
      return false;
    }
    curl_easy_setopt(curl, CURLOPT_URL, serverIp);

    /* Extract the socket from the curl handle - we'll need it for waiting. */
    res = curl_easy_getinfo(curl, CURLINFO_ACTIVESOCKET, &sockfd);

    if (res != CURLE_OK) {
      printf("Error: %s\n", curl_easy_strerror(res));
      return false;
    }
  }
  return true;
}

bool http::recvDataByCurl() {
  printf("Reading response.\n");

  for (;;) {
    /* Warning: This example program may loop indefinitely (see above). */

    size_t nread;
    do {
      nread = 0;
      res = curl_easy_recv(curl, buf, sizeof(buf), &nread);

      if (res == CURLE_AGAIN && !wait_on_socket(sockfd, 1, 60000L)) {
        printf("Error: timeout.\n");
        return false;
      }
    } while (res == CURLE_AGAIN);

    if (res != CURLE_OK) {
      printf("Error: %s\n", curl_easy_strerror(res));
      break;
    }

    if (nread == 0) {
      /* end of the response */
      break;
    }

    printf("Received %" CURL_FORMAT_CURL_OFF_T " bytes.\n", (curl_off_t)nread);
  }

  return true;
}

bool http::connectServer() {

  if (!CFG.Load()) {
    return false;
  }

  // connect to server whose information is configured in .ini file
  auto master_server_ip = CFG.GetString("MasterServer", "server_ip");
  auto master_server_port = CFG.GetInt("MasterServer", "port");

  bool ret = initCurlLib(master_server_ip.c_str());
  return ret;
}
} // namespace adpc
