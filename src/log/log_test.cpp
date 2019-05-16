#include "log/log.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

#include "common/common_define.h"
#include "common/os.h"

using namespace adpc;

TEST_CASE("log") {
    Log::InitPath();
    SUBCASE("critical log") {
        LOG.log(LogLevel::critical, "hello critical log");
        CHECK(true);
    }

    SUBCASE("error log") {
        LOG.log(LogLevel::err, "hello error log");
        CHECK(true);
    }

    SUBCASE("warning log") {
        LOG.log(LogLevel::warn, "hello warning log");
        CHECK(true);
    }

    SUBCASE("info log") {
        LOG.log(LogLevel::info, "hello info log");
        CHECK(true);
    }

    SUBCASE("debug log") {
        LOG.log(LogLevel::debug, "hello debug log");
        CHECK(true);
    }

    SUBCASE("trace log") {
        LOG.log(LogLevel::trace, "hello trace log");
        CHECK(true);
    }
}
