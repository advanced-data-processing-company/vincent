#include "common/os.h"
#include "gtest/gtest.h"

using namespace adpc::os;

TEST(common_os, file_exists) {
    system("touch test");
    ASSERT_EQ(FileExists("test"), true);
    system("rm test");
}

TEST(common_os, file_not_exists) {
    ASSERT_EQ(FileExists("test"), false);
}
