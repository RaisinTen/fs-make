# Contributing

Note that, we have a [code of conduct](CODE_OF_CONDUCT.md). So, please don't forget to go through it before contributing to this project. If you have any question or want to contribute something to this project, please [create an issue](https://github.com/RaisinTen/fs-make/issues/new/choose) first.

Fork the repo and clone it locally with:
```sh
$ git clone https://github.com/<your-github-username>/fs-make
$ cd fs-make
```

Make changes till you are satisfied and finally [make a pull request](https://github.com/RaisinTen/fs-make/pulls).

Here are the types of contributions we are looking for:
* new features
* bug-fixes
* code refactoring
* writing tests
* documentation improvements

## Development Process

### Flex

This project uses [Flex](www.gnu.org/software/flex/) which is a scanner generator for lexing in [C and C++](https://gcc.gnu.org/). The accepted tokens are described in [`lexer.l`](lexer.l) using regular expressions. We then use `flex` to generate a scanner in C (`lex.yy.c`) which breaks down the contents of the input file into the tokens we defined.

### Bison

This project also uses [GNU Bison](www.gnu.org/software/bison/) which is used to generate a parser. The production rules of the grammar is defined in [`grammar.y`](grammar.y). We use `bison` to generate a parser in C, `grammar.tab.c` to group the tokens into various components according to the defined rules. These components together will make up what is called the [abstract syntax tree (AST)](https://en.wikipedia.org/wiki/Abstract_syntax_tree).

### Tree

The [`tree`](https://en.wikipedia.org/wiki/Tree_(command)) command is a recursive directory listing command. After the file system is made, it helps in visualizing the structure of the file system.

### Build

The [`Makefile`](Makefile) is used to build `fs-make`.

First, all the dependencies: build-essential, flex, bison and tree are installed using:
```sh
$ make install
```

After that, `fs-make` can be built by:
```sh
$ make all
```
or simply:
```sh
$ make
```

This builds the target and adds a symbolic link of the executable to `/usr/local/bin` so that the program can be run from anywhere by just mentioning its name.

The Makefile uses Automatic-Dependency Generation so that contributing by adding new files is completely hassle-free. No need to separately add recipes for newly added files. It automatically detects the new files and the files it depeneds on.

### Usage

After making the input file describing the structure of the file system, compile it into the bash script for making it using:
```sh
$ fs-make infile outfile
```

### CI/CD

GitHub Actions is used to automate the software workflow.
