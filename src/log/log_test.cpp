#include "log/log.h"
#include "gtest/gtest.h"

#include "common/os.h"

using namespace adpc;

TEST(log, create_log) {
    LOG.log(LogLevel::critical, "hello");
    ASSERT_EQ(true, true);
}
