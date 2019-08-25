#ifndef HTTP_H
#define HTTP_H
#include "3rdparty/include/http_parser/http_parser.c"
#include "config/config.h"
#include "log/log.h"
#include <curl/curl.h>
#include <curl/easy.h>
namespace adpc {
class http {
public:
  http();
  ~http();
  /*
   * apis used by client, call back function is the request
   */
  bool sendAndRecv(void (*func)(char *response), const char *request,
                   const size_t buffsize);

private:
  bool connectServer();
  bool initCurlLib(const char *serverIp);
  bool sendRequestByCurl(const char *request);
  bool recvDataByCurl();

private:
  CURL *curl;
  CURLcode res;
  curl_socket_t sockfd;
  char buf[1024];
};

} // namespace adpc

#endif // HTTP_H
