# Project overview
## Managerment
CMake
- app
- lib1
- lib2
- ...


## Code style
google style, cppcheck, clang-formt

.clang format copy from[.clang-format](https://github.com/google/jsonnet/blob/master/.clang-format "google/jsonnet/.clang-format")
## Comment
doxygen
## Languange
Cpp

## Protocol
Protobuf will be used for internal usage

## Data flow

[online discuss](https://docs.google.com/document/d/1v2jsXLpF7iKs91sIN9Z-M3vjNxYJjjfaGAXDTr3JBIs/edit?usp=sharing "online google document for discuss")

## Function distribute
- app

    main function, service entry

- liblog

    log library spdlog, glog...

- parse

    parse input data from user input through input

- analysis

    analysis user input

- database access

    - abstract interface
    - each kind of datanae impletemnt the interface
    - libdba, DataBaseAcces

- libquery

    convert user query to sql query command

- libdatagenerator

    construct data for client's query

- libhttp

    find a open-source http lib

- libimport*

    import data from database

- libclean*

    clean data imported from database

- libexplore*

    explore analysis data from data base

- libanalysis*

    in-depth analysis of data from database

- libmodel*

    create model from database

- librepresent*

    create representation for data.

library name with * is tempory, may delete in later versions, don't rely on this.
