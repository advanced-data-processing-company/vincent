#include "config/config.h"
#include "common/os.h"

#include <array>
#include <iostream>

namespace adpc {

using std::array;
using std::cerr;
using std::endl;
using std::make_unique;

/// configuration file name
const static string config_file_name{".vincent.ini"};

/// configuration file path
/// the first found will be used
const array<string, 3> config_file_relative_path{"./", "../", "./bin/"};

Config::Config() {}
Config::~Config() {}

bool Config::Load() {
    string file = get_config_file();
    if (file.empty()) {
        cerr << "can not find " << config_file_name << endl;
        return false;
    }

    config_ = make_unique<INIReader>(file);

    if (config_->ParseError() != 0) {
        cerr << file << " is invalid" << endl;
        return false;
    }

    return true;
}

string Config::GetString(const string& section, const string& key) {
    return config_->Get(section, key, "");
}

int64_t Config::GetInt(const string& section, const string& key) {
    return config_->GetInteger(section, key, 0);
}

bool Config::GetBool(const string& section, const string& key) {
    return config_->GetBoolean(section, key, false);
}

const string Config::get_config_file() {
    string file;

    for (const auto& path : config_file_relative_path) {
        file = path + config_file_name;
        if (adpc::os::FileExists(file)) {
            printf("use %s\n", file.c_str());
            break;
        }
        file.clear();
    }

    if (file.empty()) {
        // TODO(thy):write log
    }

    return file;
}

}  // namespace adpc
