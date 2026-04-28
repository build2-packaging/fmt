#if __has_include(<version>)
#include <version>
#endif

#if defined(__cpp_lib_modules) && (__cpp_lib_modules >= 202207L)
#define HAS_IMPORT_STD
#endif

#ifndef IMPORT_STD_SUPPORT
#include <chrono>
#include <string>
#include <vector>
#endif

#undef NDEBUG
#include <cassert>

#ifdef IMPORT_STD_SUPPORT
import std;
#endif

import fmt;

#include "tests.inl"
