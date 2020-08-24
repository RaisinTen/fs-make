<p align="center">
    <a href="#">
        <img src="https://github.com/RaisinTen/fs-make/raw/master/logo.svg" width="320"
            alt="fs-make logo"></a>
</p>
<p align="center">
    <a href="https://github.com/RaisinTen/fs-make/actions">
        <img src="https://github.com/RaisinTen/fs-make/workflows/C/C++%20CI/badge.svg"
            alt="CI"></a>
    <a href="LICENSE">
        <img src="https://img.shields.io/github/license/RaisinTen/fs-make"
            alt="LICENSE MIT"></a>
</p>

---

Make your project's file system from its description with **`fs-make (file system make)`**!

![example](https://github.com/RaisinTen/fs-make/raw/master/fs-make-demo.png)

## Syntax

Note that this is **not JSON** but a similar data-format. Here's what the Abstract Syntax Tree looks like.

* Files are represented by the file name placed between a pair of double quotes (`"`):
    ```
    "file-name"
    ```

* Directories are represented by the directory name in double quotes (`"`) followed by a colon (`:`) and a comma-separated (`,`) set of file and directory representations between a pair of braces (`{}`):
    ```
    "src": {
        "main.cpp",
        "CMakeLists.txt",
        "build": {
            "Makefile",
            "boink"
        },
        "includes": {
        }
    }
    ```
    When a directory contains only a single entity, the braces aren't necessary:
    ```
    "ihaveonefile": "onefile"
    ```

* The input file content can be like any of these:
  * a file
    ```
    "just a file"
    ```
  * a directory
    ```
    "lonely directory": {
        "stuff"
    }
    ```
  * an unnamed set of entities like this:
    ```
    {}
    ```
    
Here's what the Abstract Syntax Tree looks like:

![grammar graph](https://github.com/RaisinTen/fs-make/raw/master/graphviz.svg)

## Getting Started

If you're on:

### macOS

Make sure you have [Homebrew](https://brew.sh/) installed.

### Windows

Install the [Windows Subsystem for Linux](https://docs.microsoft.com/en-us/windows/wsl/install-win10) or [Cygwin](https://cygwin.com/install.html) and make sure that you have [APT](https://salsa.debian.org/apt-team/apt) installed.

### Linux

Make sure that you have [APT](https://salsa.debian.org/apt-team/apt) installed.

Clone the repo with:
```sh
$ git clone https://github.com/RaisinTen/fs-make.git
$ cd fs-make
```

Update your package lists and build **`fs-make`** using:
```sh
$ ./configure
$ make
$ make install
```

## Usage

1. Create a file (say, `description.json`) describing the structure of a directory (say, `project`).
2. Use `fs-make` to make the script file (say, `script.sh`) that generates the file system like this:
    ```sh
    $ fs-make description.json script.sh
    ```
3. Run the script to generate the file system:
    ```sh
    $ . ./script.sh
    ```
4. To verify the structure of the generated directory (in this case, `project` directory):
    ```sh
    $ tree -a project
    ```

Here's an example:

![example](https://github.com/RaisinTen/fs-make/raw/master/fs-make-demo.png)

## Code of Conduct

Please refer to the [code of conduct](CODE_OF_CONDUCT.md) for the rules for interacting with this project.

## Contributing

Please go through the [contributing](CONTRIBUTING.md) documentation to contribute to this project.

## License

This project is licensed under the [MIT License](LICENSE).
