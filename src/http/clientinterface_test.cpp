#include "clientinterface.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
using namespace adpc;
/*
 *
 * Request URL:
https://static.grammarly.com/assets/files/e75230bcd1ebcdb0bac8f3ae6710fb61/circular-bold.woff2
Request Method: GET
Status Code: 200
Remote Address: 127.0.0.1:43285
Referrer Policy: same-origin
*/

TEST_CASE("client_interface") {
  SUBCASE("on_message") {
    ClientInterface ci;

    std::string a = "GET / HTTP/1.1\r\nHost: stackoverflow.com\r\n\r\n";
    bool ret = ci.Request(a);

    CHECK(ret == true);
  }
}
