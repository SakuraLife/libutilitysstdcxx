
#ifndef ___UTILITY__STANDARD__LIBRARY__CWCHAR___
#define ___UTILITY__STANDARD__LIBRARY__CWCHAR___

#include<utility/config/utility_config.hpp>
#include<wchar.h>

#if !defined(__UTILITY_BUILD_LIB) || !defined(__UTILITY_NO_SYSHEADER)
#pragma GCC system_header
#endif

__utility_globalspace_start(utility)
  namespace sstd
  {
    using ::mbstate_t;
    using ::size_t;
    using ::tm;
    using ::wint_t;
    using ::FILE;
    using ::fwprintf;
    using ::fwscanf;
    using ::swprintf;
    using ::vfwprintf;
    using ::vswprintf;
    using ::swscanf;
    using ::vfwscanf;
    using ::vswscanf;
    using ::fgetwc;
    using ::fgetws;
    using ::fputwc;
    using ::fputws;
    using ::fwide;
    using ::getwc;
    using ::putwc;
    using ::ungetwc;
    using ::wcstod;
    using ::wcstof;
    using ::wcstold;
    using ::wcstol;
    using ::wcstoll;
    using ::wcstoul;
    using ::wcstoull;
    using ::wcscpy;
    using ::wcsncpy;
    using ::wcscat;
    using ::wcsncat;
    using ::wcscmp;
    using ::wcscoll;
    using ::wcsncmp;
    using ::wcsxfrm;
    using ::wcschr;
    using ::wcspbrk;
    using ::wcsrchr;
    using ::wcsstr;
    using ::wmemchr;
    using ::wcscspn;
    using ::wcslen;
    using ::wcsspn;
    using ::wcstok;
    using ::wmemcmp;
    using ::wmemcpy;
    using ::wmemmove;
    using ::wmemset;
    using ::wcsftime;
    using ::btowc;
    using ::wctob;
    using ::mbsinit;
    using ::mbrlen;
    using ::mbrtowc;
    using ::wcrtomb;
    using ::mbsrtowcs;
    using ::wcsrtombs;

#ifndef __UTILITY_NO_STDIN
    using ::getwchar;
    using ::vwscanf;
    using ::wscanf;
#endif

#ifndef __UTILITY_NO_STDOUT
    using ::putwchar;
    using ::vwprintf;
    using ::wprintf;
#endif
    // TODO: check const version
  }
__utility_globalspace_end(utility)

#endif // ! ___UTILITY__STANDARD__LIBRARY__CWCHAR___
