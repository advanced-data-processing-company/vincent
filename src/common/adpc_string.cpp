#include "common/adpc_string.h"

namespace adpc {
namespace adpc_string {
const vector<string> adpc_string_split(const string &src, const char del) {
    vector<string> res;
    string         tmp;

    for (const auto c : src) {
        if (c != del) {
            tmp.push_back(c);
        } else if (!tmp.empty()) {
            res.push_back(std::move(tmp));
            tmp.clear();
        }
    }

    if (!tmp.empty()) {
        res.push_back(std::move(tmp));
    }

    return res;
}
}  // namespace adpc_string
}  // namespace adpc
