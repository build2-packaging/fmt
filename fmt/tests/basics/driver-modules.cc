
// Verify that fmt headers are not available if config.fmt.modules_only is true
// @NOTE: Disabled since this is rather hard to make robust.
// We need to install headers even in modules only mode in order to allow for BMI compilation.
// Even though we suppress exporting of the -I paths, in the case of installation to a common root prefix it will likely be
// the case that the headers will be accessible via the general include paths anyway. Only way we could reasonably prevent this
// would be to install to a different subfolder; avoiding adding such complexity for now since modules installation is far
// from finalized anyway.
//#if __has_include(<fmt/version.h>) != FMT_BUILD2_HAS_HEADER
//#error fmt headers should be available for include iff config.fmt.modules_only == false
//#endif

#include <cassert>
#include <string>
#include <chrono>
#include <vector>

import fmt;

#include "tests.inl"
