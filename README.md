# vincent

medical manage system

## sql design

- online

    [sql design google document](https://docs.google.com/document/d/1QlFliN9hr0bRWUpu1whWGgTl2qbUMroOrxDV7gtdL20/edit "google document for sql design")

- offline

    see [sql_table_design](https://htmlpreview.github.io/?https://github.com/advanced-data-processing-company/vincent/blob/master/sql_table_design.html "sql_table_design.html") if you can't access the online version.Note that this document may be late than online version.
## source structure

All source files are in `src` directory, each module has its own sub-directory in `src`

## compile
 1. `cd src`
 2. `mkdir build && cd build`
 3. `cmake ..`
 4. `make`

 - **DONT** build in `src` directory

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
Briefly concludes mofifications

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




