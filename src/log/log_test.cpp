#include "log/log.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

#include "common/common_define.h"
#include "common/os.h"

using namespace adpc;

TEST_CASE("global log") {
    SUBCASE("critical log") {
        LOG.critical(0, __FILE__, __LINE__, __FUNCTION__, "hello {} log", "critical");
        CHECK(true);
    }

    SUBCASE("error log") {
        LOG.err(0, __FILE__, __LINE__, __FUNCTION__, "level of error log is {}", kerr);
        CHECK(true);
    }

    SUBCASE("warning log") {
        LOG.warn(0, __FILE__, __LINE__, __FUNCTION__, "hello %s log", "warning");
        CHECK(true);
    }

    SUBCASE("info log") {
        LOG.info(0, __FILE__, __LINE__, __FUNCTION__, "level of info log is %d", kinfo);
        CHECK(true);
    }

    SUBCASE("debug log") {
        LOG.debug(0, __FILE__, __LINE__, __FUNCTION__, "hello debug log");
        CHECK(true);
    }

    SUBCASE("trace log") {
        LOG.trace(0, __FILE__, __LINE__, __FUNCTION__, "hello trace log");
        CHECK(true);
    }
}

TEST_CASE("module log") {
    auto module = LOG.AddModule("module1", ktrace);

    SUBCASE("critical log") {
        LOG.critical(module, __FILE__, __LINE__, __FUNCTION__, "hello {} log", "critical");
        CHECK(true);
    }

    SUBCASE("error log") {
        LOG.err(module, __FILE__, __LINE__, __FUNCTION__, "level of error log is {}", kerr);
        CHECK(true);
    }

    SUBCASE("warning log") {
        LOG.warn(module, __FILE__, __LINE__, __FUNCTION__, "hello %s log", "warning");
        CHECK(true);
    }

    SUBCASE("info log") {
        LOG.info(module, __FILE__, __LINE__, __FUNCTION__, "level of info log is %d", kinfo);
        CHECK(true);
    }

    SUBCASE("debug log") {
        LOG.debug(module, __FILE__, __LINE__, __FUNCTION__, "hello debug log");
        CHECK(true);
    }

    SUBCASE("trace log") {
        LOG.trace(module, __FILE__, __LINE__, __FUNCTION__, "hello trace log");
        CHECK(true);
    }
}

TEST_CASE("use macro") {
    auto module ADPC_UNUSED = LOG.AddModule("module2", ktrace);

#define CRITICALLOG(format, ...) \
    LOG.critical(module, __FILE__, __LINE__, __FUNCTION__, format, __VA_ARGS__);

#define ERRLOG(format, ...) LOG.err(module, __FILE__, __LINE__, __FUNCTION__, format, __VA_ARGS__);

#define WARNLOG(format, ...) \
    LOG.warn(module, __FILE__, __LINE__, __FUNCTION__, format, __VA_ARGS__);

#define INFOLOG(format, ...) \
    LOG.info(module, __FILE__, __LINE__, __FUNCTION__, format, __VA_ARGS__);

    SUBCASE("critical log") {
        CRITICALLOG("hello {} log", "critical");
        CHECK(true);
    }

    SUBCASE("error log") {
        ERRLOG("level of error log is {}", kerr);
        CHECK(true);
    }

    SUBCASE("warning log") {
        LOG.warn(module, __FILE__, __LINE__, __FUNCTION__, "hello %s log", "warning");
        CHECK(true);
    }

    SUBCASE("info log") {
        INFOLOG("level of info log is %d", kinfo);
        CHECK(true);
    }
}
