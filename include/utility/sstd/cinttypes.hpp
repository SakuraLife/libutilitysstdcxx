
#ifndef ___UTILITY__STANDARD__LIBRARY__CINTTYPES___
#define ___UTILITY__STANDARD__LIBRARY__CINTTYPES___

#include<utility/config/utility_config.hpp>
#include<utility/sstd/cstdint.hpp>

#if defined(__cplusplus) && !defined(__STDC_FORMAT_MACROS)
#define __STDC_FORMAT_MACROS
#endif

#include<inttypes.h>

#if !defined(__UTILITY_BUILD_LIB) || !defined(__UTILITY_NO_SYSHEADER)
#pragma GCC system_header
#endif

#ifndef imaxabs
#undef imaxabs
#endif
#ifndef imaxdiv
#undef imaxdiv
#endif

__utility_globalspace_start(utility)
  namespace sstd
  {
    using::imaxdiv_t;
    using::imaxabs;
    using::imaxdiv;
    using::strtoimax;
    using::strtoumax;
    using::wcstoimax;
    using::wcstoumax;
  }
__utility_globalspace_end(utility)

#endif // ! ___UTILITY__STANDARD__LIBRARY__CINTTYPES___
