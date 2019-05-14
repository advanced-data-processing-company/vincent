#include "common/os.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

using namespace adpc::os;

TEST_CASE("common") {
    SUBCASE("OS") {
        SUBCASE("file exsistence") {
            // exist
            SUBCASE("file exists") {
                system("touch test");
                CHECK(FileExists("test") == true);
                system("rm test");
            }

            // not exist
            SUBCASE("file not exist") {
                CHECK(FileExists("test") == false);
            }
        }
    }
}
