# build2 Package Repository for {fmt}

This is a [build2](https://build2.org) package repository for [{fmt}](https://fmt.dev/), a modern C++ formatting library that provides a safe replacement for the `printf` family of functions.

| Package | Summary | Status |
|---|---|---|
| **[`fmt`](fmt/PACKAGE-README.md)** | C++ Formatting Library | [![cppget.org](https://img.shields.io/website/https/cppget.org/fmt.svg?down_message=offline&label=cppget.org&style=for-the-badge&up_color=blue&up_message=online)](https://cppget.org/fmt) [![queue.cppget.org](https://img.shields.io/website/https/queue.cppget.org/fmt.svg?down_message=empty&down_color=blue&label=queue.cppget.org&style=for-the-badge&up_color=orange&up_message=running)](https://queue.cppget.org/fmt) |

## Usage
If you want to use the `fmt` package in your `build2`-based project, add an appropriate repository manifest to your project's `repositories.manifest` and refer to [`fmt`'s PACKAGE README](fmt/PACKAGE-README.md).

### `repositories.manifest`
To be able to fetch the package, add one of the following prerequisites to your project's `repositories.manifest`.

**Option A: `cppget.org` (Recommended)**

Based on your project's stability requirements, choose either the [`stable` section](https://cppget.org/?about#pkg%3Acppget.org%2Fstable) for thoroughly tested versions or the [`testing` section](https://cppget.org/?about#pkg%3Acppget.org%2Ftesting) for the latest releases before they are marked as stable.
For example:

    :
    role: prerequisite
    location: https://pkg.cppget.org/1/stable
    # trust: ...

**Option B: Git Repository**

    :
    role: prerequisite
    location: https://github.com/build2-packaging/fmt.git

## Development Setup
The development setup for this repository uses the standard `bdep`-based workflow.
For general information and guidance on package maintenance, please see the [`build2` Documentation](https://build2.org/doc.xhtml).

First, clone the repository via SSH or HTTPS.

    git clone --recurse https://github.com/build2-packaging/fmt.git  # HTTPS
    git clone --recurse git@github.com:build2-packaging/fmt.git      # SSH

Inside the repository's directory, initialize your build configuration.

    bdep init -C @gcc cc config.cxx=g++ config.cxx.features.modules=true config.install.root=../.install config.dist.root=../.dist

Afterwards, use `b` or `bdep` to build, test, install, and distribute the packages.

## Issues and Notes
- Modules support is WIP, both in the `build2` package and also in `fmt` upstream. Latest versions of MSVC or Clang are recommended.
- Upstream's unit tests only support C++20 and fail for the latest C++ standard. As such, `cxx.std = 20` for the `fmt-tests` package.
- A [bug in MSVC](https://developercommunity.visualstudio.com/t/Separate-preprocessing-with-P-fails-wit/10707183) prevents successful processing of {fmt}'s C++ module and emits error C7657 (private module fragment cannot be declared before a module declaration). The workaround `cc.reprocess=true` can only be applied while consuming the `build2` package. Thus, unit tests running on Windows fail for the installed case.

## Contributing
Contributions are welcome and greatly appreciated!
Please start by [opening an issue](https://github.com/build2-packaging/fmt/issues) to report a bug, suggest an improvement, or request a version update.
This helps us coordinate efforts and avoid duplicate work.
You are then welcome to submit a [pull request](https://github.com/build2-packaging/fmt/pulls) that references the issue.
For guidance on package maintenance, please see the [`build2` Packaging Guidelines](https://build2.org/build2-toolchain/doc/build2-toolchain-packaging.xhtml).
