#include "log/log.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

#include "common/os.h"

using namespace adpc;

TEST_CASE("log") {
    SUBCASE("create_log") {
        LOG.log(LogLevel::critical, "hello");
        CHECK(true == true);
    }
}
