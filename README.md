`{fmt}` library - Build2 package
================================

See [`{fmt}` documentation](https://fmt.dev/) for usage and details.

 - `{fmt}` : https://github.com/fmtlib/fmt/
 - Build2 : https://build2.org

Note: This is the source code for the build2 package of the `{fmt}` C++ library,
the actual library sources snapshot can be found in the `./upstream/` submodule.

## Configuration Options

### Experimental C++20 modules support

Modules support is WIP, both in the `build2` package and also in `fmt` upstream. Latest versions of MSVC or Clang are recommended, and the most up-to-date version of the package with regards to modules compatibility can be used via git and the [modules branch](https://github.com/build2-packaging/fmt/tree/modules). For example, in project `repositories.manifest`:
```
:
role: prerequisite
location: https://github.com/build2-packaging/fmt.git#modules
```

Enable with `config.cxx.features.modules=true`. When enabled, by default dual mode is used meaning that the library can be consumed either through `import` or via `#include`. To enable this safely, all entities are attached to the global module (extern "C++"). See `modules_only` option for the alternative.
 - `config.fmt.enable_import_std` : Set to `true` to consume the standard library as a module when building the `fmt` module. Support dependent on compiler and std lib. Defaults to `false`.
 - `config.fmt.modules_only` : Set to `true` to enable modules-only mode for the package. In this mode, `fmt` entities are fully encapsulated in the `fmt` module meaning `#include`-based consumption cannot be mixed, and the package will not export headers. Defaults to `false`.

