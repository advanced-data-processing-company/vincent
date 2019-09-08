#ifndef PARSERINTERFACE_H
#define PARSERINTERFACE_H

#pragma once
#include "http_parser.h"
#include <assert.h>
#include <memory>

class ParserInterface {
public:
  ParserInterface();

public:
  bool parseReceivedData(char *buf, const size_t length);

public:
  void RegisterOnMessageBegin(http_cb cb);
  void RegisterOnUrl(http_data_cb cb);
  void RegisterOnStatus(http_data_cb cb);
  void RegisterOnHeaderField(http_data_cb cb);
  void RegisterOnHeaderValue(http_data_cb cb);
  void RegisterOnHeadersComplete(http_cb cb);
  void RegisterOnBody(http_data_cb cb);
  void RegisterOnMessageComplete(http_cb cb);
  void RegisterOnChunkHeader(http_cb cb);
  void RegisterOnChunkComplete(http_cb cb);

private:
  http_parser_settings settings;
  std::unique_ptr<http_parser> parser;
};

#endif // PARSERINTERFACE_H
