#include "parserinterface.h"

ParserInterface::ParserInterface() {
  parser = std::make_unique<http_parser>();
  http_parser_init(parser.get(), HTTP_REQUEST);

  // TODO(wangli)
  // may need another HTTP_RESPONSE parser
}

bool ParserInterface::parseReceivedData(char *buf, const size_t length) {
  assert(buf);

  size_t nparsed = http_parser_execute(parser.get(), &settings, buf, length);

  if (parser->upgrade) {
    /* handle new protocol */
  } else if (nparsed != 0) {
    /* Handle error. Usually just close the connection. */
  }

  return true;
}

void ParserInterface::RegisterOnMessageBegin(http_cb cb) {
  this->settings.on_message_begin = cb;
}

void ParserInterface::RegisterOnUrl(http_data_cb cb) {
  this->settings.on_url = cb;
}

void ParserInterface::RegisterOnStatus(http_data_cb cb) {
  this->settings.on_status = cb;
}

void ParserInterface::RegisterOnHeaderField(http_data_cb cb) {
  this->settings.on_header_field = cb;
}

void ParserInterface::RegisterOnHeaderValue(http_data_cb cb) {
  this->settings.on_header_value = cb;
}

void ParserInterface::RegisterOnHeadersComplete(http_cb cb) {
  this->settings.on_headers_complete = cb;
}

void ParserInterface::RegisterOnBody(http_data_cb cb) {
  this->settings.on_body = cb;
}

void ParserInterface::RegisterOnMessageComplete(http_cb cb) {
  this->settings.on_message_complete = cb;
}

void ParserInterface::RegisterOnChunkHeader(http_cb cb) {
  this->settings.on_chunk_header = cb;
}

void ParserInterface::RegisterOnChunkComplete(http_cb cb) {
  this->settings.on_chunk_complete = cb;
}
