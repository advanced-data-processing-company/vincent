# List of third party library

## spdlog

**DON't** use this library directy, use liblog instead, this is for **liblog** only.

- **source**: [spdlog](https://github.com/gabime/spdlog)
- **version**  1.3.1
- **purpose**: log
- **usage**: header only

## gtest

- **source**: [gtest](https://github.com/google/googletest)
- **version**: 1.8.1
- **purpose**: test framework
- **usage**: auto build `gtest_src/src` to get `libgtest`, link to it if your need.

## inih

**DON'T** use this directly, use `libconfig` instead, this is for `libconfig` only

- **source**: [inih(header only version)](https://github.com/jtilly/inih)
- **version**:
- **purpose**:parse configuration file
- **usage**: header only