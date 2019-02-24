
#ifndef ___UTILITY__STANDARD__LIBRARY__CWCTYPE___
#define ___UTILITY__STANDARD__LIBRARY__CWCTYPE___

#include<utility/config/utility_config.hpp>
#include<utility/sstd/cctype.hpp>
#include<wctype.h>

#if !defined(__UTILITY_BUILD_LIB) || !defined(__UTILITY_NO_SYSHEADER)
#pragma GCC system_header
#endif

#ifndef iswalnum
#undef iswalnum
#endif

#ifndef iswalpha
#undef iswalpha
#endif

#ifndef iswblank
#undef iswblank
#endif

#ifndef iswcntrl
#undef iswcntrl
#endif

#ifndef iswdigit
#undef iswdigit
#endif

#ifndef iswgraph
#undef iswgraph
#endif

#ifndef iswlower
#undef iswlower
#endif

#ifndef iswprint
#undef iswprint
#endif

#ifndef iswpunct
#undef iswpunct
#endif

#ifndef iswspace
#undef iswspace
#endif

#ifndef iswupper
#undef iswupper
#endif

#ifndef iswxdigit
#undef iswxdigit
#endif

#ifndef iswctype
#undef iswctype
#endif

#ifndef wctype
#undef wctype
#endif

#ifndef towlower
#undef towlower
#endif

#ifndef towupper
#undef towupper
#endif

#ifndef towctrans
#undef towctrans
#endif

#ifndef wctrans
#undef wctrans
#endif


__utility_globalspace_start(utility)
  namespace sstd
  {
    using ::wint_t;
    using ::wctrans_t;
    using ::wctype_t;

    using ::iswalnum;
    using ::iswalpha;
    using ::iswblank;
    using ::iswcntrl;
    using ::iswdigit;
    using ::iswgraph;
    using ::iswlower;
    using ::iswprint;
    using ::iswpunct;
    using ::iswspace;
    using ::iswupper;
    using ::iswxdigit;
    using ::iswctype;
    using ::wctype;
    using ::towlower;
    using ::towupper;
    using ::towctrans;
    using ::wctrans;

  }
__utility_globalspace_end(utility)

#endif // ! ___UTILITY__STANDARD__LIBRARY__CWCTYPE___
