#include "http_parser.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

TEST_CASE("http_parse") {
  SUBCASE("on_message_begin") {}
  SUBCASE("on_url") {}
  SUBCASE("on_status") {}
}
