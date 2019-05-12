#include "common/os.h"

#include <linux/limits.h>
#include <sys/stat.h>
#include <unistd.h>

namespace adpc {

namespace os {

bool FileExists(const string &file_full_path) {
    printf("current path is %s\n", GetCurrentDirectory().c_str());

    struct stat buf;
    int         err = stat(file_full_path.c_str(), &buf);
    return (err == 0);
}

string GetCurrentDirectory() {
    char path[PATH_MAX];

    getcwd(path, sizeof(path));
    return string(path);
}

}  // namespace os

}  // namespace adpc
