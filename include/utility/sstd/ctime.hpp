
#ifndef ___UTILITY__STANDARD__LIBRARY__CTIME___
#define ___UTILITY__STANDARD__LIBRARY__CTIME___

#include<utility/config/utility_config.hpp>
#include<time.h>

#if !defined(__UTILITY_BUILD_LIB) || !defined(__UTILITY_NO_SYSHEADER)
#pragma GCC system_header
#endif

__utility_globalspace_start(utility)
  namespace sstd
  {
    using ::clock_t;
    using ::size_t;
    using ::time_t;
    using ::tm;

    using ::clock;
    using ::difftime;
    using ::mktime;
    using ::time;
#ifndef __UTILITY_NO_THREAD_UNSAFE
    using ::asctime;
    using ::ctime;
    using ::gmtime;
    using ::localtime;
#endif
    using ::strftime;

#if !defined(__UTILITY_NO_CPP14__)
    // TODO: timespec, timespec_get
    // using ::timespec;
    // using ::timespec_get;
#endif
  }
__utility_globalspace_end(utility)

#endif // ! ___UTILITY__STANDARD__LIBRARY__CTIME___
