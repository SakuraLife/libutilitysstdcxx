


/*!
* \file cstring.hpp
* \author Inochi Amaoto
* \date 2017-09-13
* \brief sstd cstring library
* a head file like cstring, but the dangerous functions are
* removed. All the function has null pointer check.
*/


#ifndef ___UTILITY__STANDARD__LIBRARY__CSTRING___
#define ___UTILITY__STANDARD__LIBRARY__CSTRING___

#include<utility/config/utility_config.hpp>
#include<string.h>

#if !defined(__UTILITY_BUILD_LIB) || !defined(__UTILITY_NO_SYSHEADER)
#pragma GCC system_header
#endif

__utility_globalspace_start(utility)
  namespace sstd
  {
    using ::size_t;
    using ::memcpy;
    using ::memmove;
    using ::strcpy;
    using ::strncpy;
    using ::strcat;
    using ::strncat;
    using ::memcmp;
    using ::strcmp;
    using ::strncmp;
    using ::strcoll;
    using ::strxfrm;
    using ::memchr;
    using ::strchr;
    using ::strcspn;
    using ::strpbrk;
    using ::strrchr;
    using ::strspn;
    using ::strstr;
#ifndef __UTILITY_NO_THREAD_UNSAFE
    using ::strtok;
#endif
    using ::memset;
    using ::strerror;
    using ::strlen;

    // TODO: check const version
  }
__utility_globalspace_end(utility)

#endif // ! ___UTILITY__STANDARD__LIBRARY__CSTRING___
