#include "config/config.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

#include "iostream"
#include "string"

using std::cerr;
using std::endl;
using std::string;

TEST_CASE("configuration") {
    if (!CFG.Load()) {
        cerr << "load file failed" << endl;
        return;
    }

    CHECK(CFG.GetInt("log", "log_file_size") == 10);
    CHECK(CFG.GetString("log", "log_file_base_name") == string("daily_file"));
    CHECK(CFG.GetString("log", "split_string") == string("hello split"));
    CHECK(CFG.GetBool("log", "Bool") == true);
}
