
#ifndef ___UTILITY__STANDARD__LIBRARY__CLOCALE___
#define ___UTILITY__STANDARD__LIBRARY__CLOCALE___

#include<utility/config/utility_config.hpp>
#include<locale.h>

#if !defined(__UTILITY_BUILD_LIB) || !defined(__UTILITY_NO_SYSHEADER)
#pragma GCC system_header
#endif

#ifdef setlocale
#undef setlocale
#endif

#ifdef localeconv
#undef localeconv
#endif

__utility_globalspace_start(utility)
  namespace sstd
  {
    using ::lconv;

#if !defined(__UTILITY_NO_THREAD_UNSAFE)
    using ::setlocale;
#endif
    using ::localeconv;
  }
__utility_globalspace_end(utility)

#endif // ! ___UTILITY__STANDARD__LIBRARY__CLOCALE___
