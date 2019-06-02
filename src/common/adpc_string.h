#pragma once

#include <string>
#include <vector>

namespace adpc {
namespace adpc_string {
using std::string;
using std::vector;

/**
 * @brief split string to vector with delimeter
 * @param src   string to be splitted
 * @param del   delimeter
 * @return      splitted string i vector
 */
const vector<string> adpc_string_split(const string &src, const char del);

}  // namespace adpc_string
}  // namespace adpc
