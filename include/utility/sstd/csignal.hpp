
#ifndef ___UTILITY__STANDARD__LIBRARY__CSIGNAL___
#define ___UTILITY__STANDARD__LIBRARY__CSIGNAL___

#include<utility/config/utility_config.hpp>
#include<signal.h>

#if !defined(__UTILITY_BUILD_LIB) || !defined(__UTILITY_NO_SYSHEADER)
#pragma GCC system_header
#endif

__utility_globalspace_start(utility)
  namespace sstd
  {
    using ::sig_atomic_t;
    using ::signal;
    using ::raise;
  }
__utility_globalspace_end(utility)

#endif // ! ___UTILITY__STANDARD__LIBRARY__CSIGNAL___
