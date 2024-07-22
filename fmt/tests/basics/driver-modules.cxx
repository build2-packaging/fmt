
// Verify that fmt headers are not available if config.fmt.modules_only is true
#if __has_include(<fmt/version.h>) != FMT_BUILD2_HAS_HEADER
#error fmt headers should be available for include iff config.fmt.modules_only == false
#endif

#include <cassert>
#include <string>
#include <chrono>
#include <vector>

import fmt;

#include "tests.inl"
