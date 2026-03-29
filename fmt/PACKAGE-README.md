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
#include <fmt/base.h>     // Base API
#include <fmt/format.h>   // Formatting Functions and Locale Support
#include <fmt/ranges.h>   // Formatting of Ranges and Tuples
#include <fmt/chrono.h>   // Date and Time Formatting
#include <fmt/std.h>      // Formatting for Standard Library Types
#include <fmt/compile.h>  // Format String Compilation
#include <fmt/color.h>    // Terminal Colors and Text Styles
#include <fmt/os.h>       // System APIs
#include <fmt/ostream.h>  // `std::ostream` Support
#include <fmt/args.h>     // Dynamic Argument Lists
#include <fmt/printf.h>   // Safe `printf`
#include <fmt/xchar.h>    // Optional `wchar_t` Support
```

If `$fmt.has_module == true`, {fmt}'s C++ module can imported via:

```c++
import fmt;
```

## Configuration

### C++20 Modules Support
{fmt}'s C++ module can be enabled with `config.cxx.features.modules=true`.
In this case, the library by default can be consumed via module importation through `import fmt;` and header inclusion through, eg., `#include <fmt/format.h>`.
For this to work, all entities are attached to the global module via global module linkage through `extern "C++"`.

To make entities use module linkage, we must disable header access by using `config.fmt.module_only=true`.
In this case, all entities are fully encapsulated in {fmt}'s C++ module.

{fmt}'s C++ module uses importation of the C++ standard library module via `import std;` by default.
For backwards compatibility, this can be disabled by `config.fmt.disable_import_std=true`.
