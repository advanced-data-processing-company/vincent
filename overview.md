# Project overview
## managerment
CMake
- app
- lib1
- lib2
- ...


## Code style
google style, cppcheck, clang-formt
## Comment
doxygen
## Languange
Cpp

## Data flow

[online discuss](https://docs.google.com/document/d/1v2jsXLpF7iKs91sIN9Z-M3vjNxYJjjfaGAXDTr3JBIs/edit?usp=sharing "online google document for discuss")

## function distribute
- app

    main function, service entry

- database access

    - abstract interface
    - each kind of datanae impletemnt the interface
    - libdba, DataBaseAcces

- 
