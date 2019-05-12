/**
 * @file os.h
 * @author tonghao.yuan (michael.19@163.com)
 * @brief os relative convinient functions
 * @version 0.1
 * @date 2019-05-12
 *
 * @copyright Copyright (c) 2019
 *
 */

#include <string>

namespace adpc {

using std::string;

namespace os {
/**
 * @brief check if a file exists.
 * @param file_full_path full path to the file, relative or absolute path both ok
 * @return true for exists, false for not
 */
bool   FileExists(const string &file_full_path);
string GetCurrentDirectory();
}  // namespace os

}  // namespace adpc
