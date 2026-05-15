# {fmt} - A Formatting C++ Library

{fmt} is an open-source formatting library that provides a safe replacement for the `printf` family of functions.
Errors in format strings, which are a common source of vulnerabilities in C, are reported at compile time.
Formatting of most standard types, including all containers, dates, and times is supported out-of-the-box.
Also, {fmt} provides portable Unicode support on major operating systems with UTF-8 and char strings.

# Usage
To use `fmt` in your project, add the following configurations to the respective files after you have gained access to a `build2` package repository that contains it.

### `manifest`
To make `fmt` available for import, add the following dependency to the `manifest` of each package in your project that requires it, adjusting the version constraint as appropriate.

    depends: fmt ^12.1.0

### `buildfile`
To import the contained library, use the following declaration in your `buildfile`.

    import fmt = fmt%lib{fmt}

Note also that `lib{fmt}` provides `build2` metadata that can be extracted with an immediate importation to describe its configuration.

    fmt.has_header = [bool] (!$config.fmt.module_only)
    fmt.has_module = [bool] $cxx.features.modules

### C++ Usage
If `$fmt.has_header == true`, {fmt}'s headers can be included as follows:

```c++
#include <fmt/format.h>
```

If `$fmt.has_module == true`, {fmt}'s C++ module can imported via:

```c++
import fmt;
```

## Configuration

### C++20 Modules Support
{fmt}'s C++ module support can be enabled by setting:

    config.cxx.features.modules = true

By default, the library supports both module import through `import fmt;` and traditional header inclusion through, eg., `#include <fmt/format.h>`.
To enable this dual usage, all entities are attached to the global module via global module linkage (`extern "C++"`).
This ensures compatibility between module and header-based consumption.

To enforce strict module usage, use:

    config.fmt.module_only = true

In this mode, header access is disabled and all entities are exclusively provided through the C++ module.
This results in full encapsulation within the module and avoids global module linkage.
