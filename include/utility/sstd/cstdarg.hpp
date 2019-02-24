
#ifndef ___UTILITY__STANDARD__LIBRARY__CSTDARG___
#define ___UTILITY__STANDARD__LIBRARY__CSTDARG___

#include<utility/config/utility_config.hpp>
#include<stdarg.h>

#if !defined(__UTILITY_BUILD_LIB) || !defined(__UTILITY_NO_SYSHEADER)
#pragma GCC system_header
#endif

__utility_globalspace_start(utility)
  namespace sstd
  {
    using ::va_list;
  }
__utility_globalspace_end(utility)

#endif // ! ___UTILITY__STANDARD__LIBRARY__CSTDARG___
