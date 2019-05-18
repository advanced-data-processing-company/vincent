#include "http/http.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

#include "common/common_define.h"
#include "common/os.h"

using namespace adpc;

TEST_CASE("http") {
    ClusterCurl::globalInit();
    SUBCASE("setConnectTimeout") {
        HTTP.setConnectTimeout(1);
        CHECK(true);
    }

    SUBCASE("setTimeout") {
        HTTP.setTimeout(1);
        CHECK(true);
    }

    SUBCASE("globalCleanup") {
        HTTP.globalCleanup();
        CHECK(true);
    }
}