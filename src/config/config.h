#pragma once

#include <memory>
#include <string>

#include "inih/INIReader.h"

#include "adpctl/singleton.h"

using std::string;
using std::unique_ptr;

namespace adpc {

/**
 * @brief The Config class
 *
 * read config file
 */
class Config {
    friend adpctl::Singleton<Config>;

   public:
    bool Load();

    /**
     * @brief getter
     * @{
     */

    /**
     * @brief get string value
     * @param section   section name
     * @param key       key name
     * @return          return value or empty string if not found
     */
    string GetString(const string& section, const string& key);

    /**
     * @brief Get integer value
     * @param section   section name
     * @param key       key name
     * @return          return value or `0` if not found
     */
    int64_t GetInt(const string& section, const string& key);

    /**
     * @brief Get boolean value
     * @param section   section name
     * @param key       key name
     * @return          return value or `false` if not found
     */
    bool GetBool(const string& section, const string& key);

    /** @} */

   private:
    Config();
    ~Config();

    const string get_config_file();

   private:
    unique_ptr<INIReader> config_{nullptr};
};

/// convinent macro for singleton instance
#define CFG adpctl::Singleton<adpc::Config>::GetInstance()

}  // namespace adpc
