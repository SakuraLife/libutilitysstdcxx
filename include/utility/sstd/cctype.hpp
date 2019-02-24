
#ifndef ___UTILITY__STANDARD__LIBRARY__CCTYPE___
#define ___UTILITY__STANDARD__LIBRARY__CCTYPE___

#include<utility/config/utility_config.hpp>
#include<ctype.h>

#if !defined(__UTILITY_BUILD_LIB) || !defined(__UTILITY_NO_SYSHEADER)
#pragma GCC system_header
#endif

#ifdef isalnum
#undef isalnum
#endif

#ifdef isalpha
#undef isalpha
#endif

#ifdef isblank
#undef isblank
#endif

#ifdef iscntrl
#undef iscntrl
#endif

#ifdef isdigit
#undef isdigit
#endif

#ifdef isgraph
#undef isgraph
#endif

#ifdef islower
#undef islower
#endif

#ifdef isprint
#undef isprint
#endif

#ifdef ispunct
#undef ispunct
#endif

#ifdef isspace
#undef isspace
#endif

#ifdef isupper
#undef isupper
#endif

#ifdef isxdigit
#undef isxdigit
#endif

#ifdef tolower
#undef tolower
#endif

#ifdef toupper
#undef toupper
#endif

__utility_globalspace_start(utility)
  namespace sstd
  {
    using ::isalnum;
    using ::isalpha;
    using ::isblank;
    using ::iscntrl;
    using ::isdigit;
    using ::isgraph;
    using ::islower;
    using ::isprint;
    using ::ispunct;
    using ::isspace;
    using ::isupper;
    using ::isxdigit;
    using ::tolower;
    using ::toupper;
  }
__utility_globalspace_end(utility)

#endif // ! ___UTILITY__STANDARD__LIBRARY__CCTYPE___
