
#ifndef ___UTILITY__STANDARD__LIBRARY__CSTDLIB___
#define ___UTILITY__STANDARD__LIBRARY__CSTDLIB___

#include<utility/config/utility_config.hpp>
#include<stdlib.h>

#if !defined(__UTILITY_BUILD_LIB) || !defined(__UTILITY_NO_SYSHEADER)
#pragma GCC system_header
#endif

#ifndef abs
#undef abs
#endif

#ifndef div
#undef div
#endif

#ifndef labs
#undef labs
#endif

#ifndef ldiv
#undef ldiv
#endif

#ifndef llabs
#undef llabs
#endif

#ifndef lldiv
#undef lldiv
#endif


__utility_globalspace_start(utility)
  namespace sstd
  {
    using ::size_t;
    using ::div_t;
    using ::ldiv_t;
    using ::lldiv_t;
    using ::atof;
    using ::atoi;
    using ::atol;
    using ::atoll;
    using ::strtod;
    using ::strtof;
    using ::strtold;
    using ::strtol;
    using ::strtoll;
    using ::strtoul;
    using ::strtoull;
    using ::rand;
    using ::srand;
    using ::calloc;
    using ::free;
    using ::malloc;
    using ::realloc;
    using ::abort;
    using ::atexit;
    using ::exit;
    using ::_Exit;
    using ::bsearch;
    using ::qsort;
    using ::abs;
    using ::labs;
    using ::llabs;
    using ::div;
    using ::ldiv;
    using ::lldiv;
    using ::mblen;
    using ::mbtowc;
    using ::wctomb;
    using ::mbstowcs;
    using ::wcstombs;

    // TODO: at_quick_exit, quick_exit, aligned_alloc, getenv, system
    // TODO: abs div(l_t, ll_t)
    // using ::at_quick_exit;
    // using ::quick_exit;
    // using ::aligned_alloc;
    // using ::getenv;
    // using ::system;
  }
__utility_globalspace_end(utility)

#endif // ! ___UTILITY__STANDARD__LIBRARY__CSTDLIB___

#define RAND_MAX 0x7fff
