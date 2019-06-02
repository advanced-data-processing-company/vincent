#include "websocket_server/cmd_factory.h"

#include "doctest/doctest.h"

#include <iostream>
//#include <string>
//#include <vector>

using std::cout;
using std::string;

// int main() {
//    for (const auto& kv : wscmd::CommandFactory::cmd_create_map_) {
//        cout << kv.first << "\n";
//    }
//}

TEST_CASE("websocket_servr") {
    SUBCASE("log_cmd") {
        SUBCASE("infomation") {
            string cmd_str_list("log list");
            auto   cmd = wscmd::CommandFactory::CreateCmd(cmd_str_list);

            if (cmd) {
                cout << cmd->Execute() << "\n";
            } else {
                cout << "cmd not found\n";
            }
        }

        SUBCASE("set") {
            string cmd_str_list("log set -l 1 -m 0");
            auto   cmd = wscmd::CommandFactory::CreateCmd(cmd_str_list);
            if (cmd) {
                cout << cmd->Execute() << "\n";
            } else {
                cout << "cmd not found\n";
            }
        }

        SUBCASE("reset") {
            string cmd_str_list("log reset -m 0");
            auto   cmd = wscmd::CommandFactory::CreateCmd(cmd_str_list);
            if (cmd) {
                cout << cmd->Execute() << "\n";
            } else {
                cout << "cmd not found\n";
            }
        }
    }
}
