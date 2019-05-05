# Vincent

medical manage system.
[![Build Status](https://travis-ci.org/advanced-data-processing-company/vincent.svg?branch=master)](https://travis-ci.org/advanced-data-processing-company/vincent)
[![Build status](https://ci.appveyor.com/api/projects/status/f69xmttanl5kc00m?svg=true)](https://ci.appveyor.com/project/maidamai0/vincent)
[![Total alerts](https://img.shields.io/lgtm/alerts/g/advanced-data-processing-company/vincent.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/advanced-data-processing-company/vincent/alerts/)
[![Language grade: JavaScript](https://img.shields.io/lgtm/grade/javascript/g/advanced-data-processing-company/vincent.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/advanced-data-processing-company/vincent/context:javascript)

## Sql design

- Online

    [sql design google document](https://docs.google.com/document/d/1QlFliN9hr0bRWUpu1whWGgTl2qbUMroOrxDV7gtdL20/edit "google document for sql design")

- Offline

    see [sql_table_design](https://htmlpreview.github.io/?https://github.com/advanced-data-processing-company/vincent/blob/master/sql_table_design.html "sql_table_design.html") if you can't access the online version.Note that this document may be late than online version.
## Source structure

All source files are in `src` directory, each module has its own sub-directory in `src`

## Build
 1. `cd ${VINCENT_ROOT_PATH}`
 2. `mkdir build && cd build`
 3. `cmake ..`
 4. `make`

 - **DONT** build in `src` directory
 - If you dont want to build `doxygen docs` call cmake with
    ```
    cmake -DBUILD_DOC=OFF ..
    ```

 ## Git commit message
 ### Reasons for these conventions
  - automatic generating changelog
  - simple navigation through git history

### Format of git commit message
```
<type>(<scope>): <subject>
# blank line
<body>
# blank line
<footer>
```
### Example commit message
```
fix(app): avoid memory leak

use smart pointer to avoid memory leak

#2310
```
### first line
The first line cannot be longer than 70 characters, the second line is always blank and other lines should be wrapped at 80 characters. The type and scope should always be lowercase as shown below.
#### Allowed \<type> values
- feat (new feature for the user, not a new feature for build script)
- fix (bug fix for the user, not a fix to a build script)
- docs (changes to the documentation)
- style (formatting, missing semi colons, etc; no - production code change)
- refactor (refactoring production code, eg. renaming a variable)
- test (adding missing tests, refactoring tests; no production code change)
- chore (updating grunt tasks etc; no production code change)

#### \<scope>

Generally `<scope>` value should be  the module name, such as `app`

#### \<subject>
Briefly concludes modifications

### Message body
- uses the imperative, present tense: “change” not “changed” nor “changes”
- includes motivation for the change and contrasts with previous behavior

### Footter
issue or feature number

### Config git to use `commit.template`
`git config --global commit.template ./.gitcommitstyle.txt`

### Reference
- [karam git commit style](http://karma-runner.github.io/4.0/dev/git-commit-msg.html)
- [git config](https://git-scm.com/book/en/v2/Customizing-Git-Git-Configuration)

## Unit test
every library should has a executable to do test, test excutable name should end with library name plus `_test`

take `proto` for example, its test executable is `proto_test`,when built you can run test with
```
cd build
bin/proto_test
```
**Don't** forget to add `target_link_libraries(xxx_test gtest)` to your `CMakeLists.txt` to link `gtest`

and it should give something like
```
Running main() from /home/thy/Documents/vincent/src/3rdparty/src/gtest_main.cc
[==========] Running 2 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 2 tests from json
[ RUN      ] json.to_json
[       OK ] json.to_json (0 ms)
[ RUN      ] json.from_json
[       OK ] json.from_json (0 ms)
[----------] 2 tests from json (0 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 2 tests.
```

`make && make test`

```
Running tests...
/usr/bin/ctest --force-new-ctest-process 
Test project /home/thy/Documents/vincent/build
    Start 1: proto
1/2 Test #1: proto ............................   Passed    0.00 sec
    Start 2: log
2/2 Test #2: log ..............................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 2

Total Test time (real) =   0.01 sec
```
