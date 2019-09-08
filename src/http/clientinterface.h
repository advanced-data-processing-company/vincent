#ifndef CLIENTINTERFACE_H
#define CLIENTINTERFACE_H

#pragma once
#include "http_parser/http_parser.h"
#include "http_parser/parserinterface.h"
#include "log/log.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include <string>

using std::string;
typedef std::string JSON_STRING;

enum class HTTP_CODE { HTTP_OK = 200, HTTP_NOT_FOUND = 404 };
enum class REQ_METHOD { CREATE, RETRIVE, UPDATE, DELETE };

namespace adpc {
class ClientInterface {

  // friend adpctl::Singleton<ClientInterface>;

  friend int on_message_begin(http_parser *);
  friend int on_url(http_parser *, const char *at, size_t length);
  friend int on_headers_complete(http_parser *parser);
  friend int on_header_field(http_parser *parser, const char *p, size_t length);

public:
  ClientInterface();

public:
  bool ConnectHttpServer(const JSON_STRING &configure);
  void DisconnectHttpServer();
  bool Request(const std::string &url);

private:
  HTTP_CODE CreateContent(const std::string &url, JSON_STRING &response);
  HTTP_CODE RetriveContent(const std::string &url, JSON_STRING &response);
  HTTP_CODE UpdateContent(const std::string &url, JSON_STRING &response);
  HTTP_CODE DeleteContent(const std::string &url, JSON_STRING &response);

  ParserInterface pi;
};

//#define LOG adpctl::Singleton<adpc::ClientInterface>::GetInstance()

} // namespace adpc
int on_message_begin(http_parser *parser);
int on_headers_complete(http_parser *parser);

int on_url(http_parser *parser, const char *p, size_t length);
int on_header_field(http_parser *parser, const char *p, size_t length);
#endif // CLIENTINTERFACE_H
