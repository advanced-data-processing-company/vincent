#include "common/adpc_string.h"
#include "doctest/doctest.h"

using namespace adpc::adpc_string;

TEST_CASE("common") {
    SUBCASE("adpc_string") {
        SUBCASE("split_string") {
            string ss  = "I have a dream";
            auto   vec = adpc_string_split(ss, ' ');

            CHECK_EQ(vec.size(), 4);
            CHECK_EQ(vec[0], "I");
            CHECK_EQ(vec[1], "have");
            CHECK_EQ(vec[2], "a");
            CHECK_EQ(vec[3], "dream");

            ss  = "  I have another dream   ";
            vec = adpc_string_split(ss, ' ');
            CHECK_EQ(vec.size(), 4);
            CHECK_EQ(vec[0], "I");
            CHECK_EQ(vec[1], "have");
            CHECK_EQ(vec[2], "another");
            CHECK_EQ(vec[3], "dream");
        }
    }
}
