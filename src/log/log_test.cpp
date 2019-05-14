#include "log/log.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

#include "common/common_define.h"
#include "common/os.h"

using namespace adpc;

TEST_CASE("log") {
    Log::InitPath();
    SUBCASE("create_log") {
        LOG.log(LogLevel::critical, "hello");
        CHECK(true);
    }
}
