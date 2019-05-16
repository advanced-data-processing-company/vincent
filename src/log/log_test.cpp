#include "log/log.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

#include "common/common_define.h"
#include "common/os.h"

using namespace adpc;

TEST_CASE("global log") {
    Log::InitPath();
    SUBCASE("critical log") {
        LOG.log(0, LogLevel::critical, "hello critical log");
        CHECK(true);
    }

    SUBCASE("error log") {
        LOG.log(0, LogLevel::err, "hello error log");
        CHECK(true);
    }

    SUBCASE("warning log") {
        LOG.log(0, LogLevel::warn, "hello warning log");
        CHECK(true);
    }

    SUBCASE("info log") {
        LOG.log(0, LogLevel::info, "hello info log");
        CHECK(true);
    }

    SUBCASE("debug log") {
        LOG.log(0, LogLevel::debug, "hello debug log");
        CHECK(true);
    }

    SUBCASE("trace log") {
        LOG.log(0, LogLevel::trace, "hello trace log");
        CHECK(true);
    }
}

TEST_CASE("module log") {
    Log::InitPath();
    auto module = LOG.AddModule("module", trace);

    SUBCASE("critical log") {
        LOG.log(module, LogLevel::critical, "hello critical log");
        CHECK(true);
    }

    SUBCASE("error log") {
        LOG.log(module, LogLevel::err, "hello error log");
        CHECK(true);
    }

    SUBCASE("warning log") {
        LOG.log(module, LogLevel::warn, "hello warning log");
        CHECK(true);
    }

    SUBCASE("info log") {
        LOG.log(module, LogLevel::info, "hello info log");
        CHECK(true);
    }

    SUBCASE("debug log") {
        LOG.log(module, LogLevel::debug, "hello debug log");
        CHECK(true);
    }

    SUBCASE("trace log") {
        LOG.log(module, LogLevel::trace, "hello trace log");
        CHECK(true);
    }
}
