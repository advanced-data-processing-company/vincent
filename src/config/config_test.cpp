#include "config/config.h"
#include "gtest/gtest.h"

#include "iostream"
#include "string"

using std::cerr;
using std::endl;
using std::string;

TEST(config, load_file) {
    if (!CFG.Load()) {
        cerr << "load file failed" << endl;
        return;
    }

    ASSERT_EQ(CFG.GetInt("log", "log_file_size"), 10);
    ASSERT_EQ(CFG.GetString("log", "log_file_base_name"), string("daily_file"));
    ASSERT_EQ(CFG.GetString("log", "split_string"), string("hello split"));
    ASSERT_EQ(CFG.GetBool("log", "Bool"), true);
}
