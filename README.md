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
- To generate a Binary Module Interface (BMI) from {fmt}'s C++ module after installation, the consumer must compile the module interface unit using the same macro configuration as the original library build. These macros are internal to the module and are therefore not exported via `cxx.export.poptions`. Instead, a generated `config.h` header encapsulates the required configuration through preprocessor macros. The module interface unit is patched to include this header immediately after `module;` in the global module fragment, ensuring the correct macros are available during BMI generation.
- In non-modular compiled builds, `fmt/format-inl.h` acts as a private implementation header for `src/format.cc`. While its installation in this specific configuration is technically unnecessary, we do not explicitly exclude it to reduce complexity.
- C++ module support in GCC versions prior to 16 is incomplete and unreliable for this library. As a result, such configurations are considered unsupported and are excluded from CI.
- On FreeBSD 15 with Clang 19, there is a discrepancy between compiler capabilities and system libraries. Although `__cpp_lib_modules` is defined (indicating that libc++ has module support), the base system does not ship the required module source or metadata files. Consequently, `import std;` is not functional in this environment which is reflected in the generated `config.h`.
- Upstream unit tests currently only support C++20 and fail when compiled with newer language standards. Therefore, the `fmt-tests` package is explicitly restricted to `cxx.std = 20`.
- Currently, unit tests are only run when the library headers are available and not when `config.fmt.module_only=true`. The unit tests use standard header includes rather than module imports.
- A known [issue in MSVC](https://developercommunity.visualstudio.com/t/Separate-preprocessing-with-P-fails-wit/10707183) prevents correct processing of {fmt}'s C++ module, producing error C7657 (“private module fragment cannot be declared before a module declaration”). The workaround (`cc.reprocess=true`) is only applicable when consuming the package directly via `build2`. As a result, unit tests fail on Windows when using the installed package.

## Contributing
Contributions are welcome and greatly appreciated!
Please start by [opening an issue](https://github.com/build2-packaging/fmt/issues) to report a bug, suggest an improvement, or request a version update.
This helps us coordinate efforts and avoid duplicate work.
You are then welcome to submit a [pull request](https://github.com/build2-packaging/fmt/pulls) that references the issue.
For guidance on package maintenance, please see the [`build2` Packaging Guidelines](https://build2.org/build2-toolchain/doc/build2-toolchain-packaging.xhtml).
