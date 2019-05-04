/**
 * @file main.cpp
 * @author tonghao.yuan (michael.19@163.com)
 * @brief
 * @version 0.1
 * @date 2019-05-04
 *
 * @copyright Copyright (c) 2019
 *
 */

#include <iostream>
#include <string>

#include "common/common_define.h"

ADPC_DEPRECATED("use fun_new instead")
void fun(int i ADPC_UNUSED) {
    std::cout << "unused function" << std::endl;
    return;
}

void fun_new(int i ADPC_UNUSED) {
    std::cout << "unused function" << std::endl;
    return;
}

int main(int argc ADPC_UNUSED, char** argv ADPC_UNUSED) {
    int a = 4;

    if (ADPC_LIKELY(a > 1)) {
        std::cout << "likely";
    }

    if (ADPC_UNLIKELY(a > 5)) {
        std::cout << "unlikely";
    }

    ADPC_ASSERT(a == 5, "a must be 5");

    std::cout << "hello vincent!" << std::endl;
}
