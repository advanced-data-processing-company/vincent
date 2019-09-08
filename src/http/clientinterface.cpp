#include "clientinterface.h"

ClientInterface::ClientInterface() {
  pi.RegisterOnUrl(&on_url);
  pi.RegisterOnMessageBegin(&on_message_begin);
  pi.RegisterOnHeadersComplete(&on_headers_complete);
  pi.RegisterOnHeaderField(&on_header_field);
}

bool ClientInterface::ConnectHttpServer(const JSON_STRING &configure) {

  printf("%s", configure.c_str());
  return false;
}

int on_message_begin(http_parser *parser) {

  printf("on_message_begin = %d\n", parser->method);
  return 0;
}

int on_url(http_parser *parser, const char *p, size_t length) {
  assert(parser);

  printf("on_url p = %s, length = %d\n", p, static_cast<int>(length));
  return 0;
}

int on_headers_complete(http_parser *parser) {

  printf("on_headers_complete %d\n", parser->method);

  return 0;
}

int on_header_field(http_parser *parser, const char *p, size_t length) {

  printf("on_header_field %d %s %zd\n", parser->method, p, length);
  return 0;
}

void ClientInterface::DisconnectHttpServer() {}

bool ClientInterface::Request(const std::string &url) {

  if (url.empty()) {
    // LOG.err(0, __FILE__, __LINE__, __FUNCTION__, "Invaild parameter:url");
    return false;
  }

  bool ret =
      pi.parseReceivedData(const_cast<char *>(url.c_str()), url.length());

  return ret;
}

HTTP_CODE ClientInterface::CreateContent(const std::string &url,
                                         JSON_STRING &response) {

  printf("%s, %s", url.c_str(), response.c_str());
  return HTTP_CODE::HTTP_NOT_FOUND;
}

HTTP_CODE ClientInterface::RetriveContent(const std::string &url,
                                          JSON_STRING &response) {
  printf("%s, %s", url.c_str(), response.c_str());
  return HTTP_CODE::HTTP_NOT_FOUND;
}

HTTP_CODE ClientInterface::UpdateContent(const std::string &url,
                                         JSON_STRING &response) {
  printf("%s, %s", url.c_str(), response.c_str());
  return HTTP_CODE::HTTP_NOT_FOUND;
}

HTTP_CODE ClientInterface::DeleteContent(const std::string &url,
                                         JSON_STRING &response) {
  printf("%s, %s", url.c_str(), response.c_str());
  return HTTP_CODE::HTTP_NOT_FOUND;
}
