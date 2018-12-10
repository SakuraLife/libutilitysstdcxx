


/*!
* \file cstring.hpp
* \author Inochi Amaoto
* \date 2017-09-13
* \brief sstd cstring library
* a head file like cstring, but the dangerous functions are
* removed. All the function has null pointer check.
*/


#ifndef ___UTILITY__STANDARD__LIBRARY__CSTDING___
#define ___UTILITY__STANDARD__LIBRARY__CSTDING___

#include<utility/config/utility_config.hpp>

#ifndef EOF
# define EOF (-1)
#endif // ! EOF

#ifndef __WINT_TYPE__
# define __WINT_TYPE__ unsigned int
#endif // ! __WINT_TYPE__
#ifndef WEOF
# define WEOF (0xffffffffu)
#endif // ! WEOF

extern "C++"
{

namespace utility
{
  namespace sstd
  {
    // Constant
    typedef __WINT_TYPE__ wint_t;
    constexpr wchar_t weof = static_cast<wchar_t>(WEOF);

    // Typemake clear
    struct mbstate_t
    {
      int __count;
      union
      {
        wint_t __wch;
        char __wchb[4];
      } __value;
    };

    // Helper
    extern char* strend(char* _str) noexcept;
    extern const char* strend(const char* _str) noexcept;
    extern size_t strlen(const char* _str) noexcept;
    extern size_t strnlen(const char* _str, size_t _mlen) noexcept;
    extern wchar_t* wcsend(wchar_t* _wstr) noexcept;
    extern const wchar_t* wcsend(const wchar_t* _wstr) noexcept;
    extern size_t wcslen(const wchar_t* _wstr) noexcept;
    extern size_t wcsnlen(const wchar_t* _wstr, size_t _mlen) noexcept;

    // Copying
    extern char* strcpy(char* _dest, const char* _src) noexcept;
    extern char* stpcpy(char* _dest, const char* _src) noexcept;
    extern char* strncpy(char* _dest, const char* _src, size_t _size) noexcept;
    extern char* stpncpy(char* _dest, const char* _src, size_t _size) noexcept;
    extern wchar_t* wcscpy(wchar_t* _wdest, const wchar_t* _wsrc) noexcept;
    extern wchar_t* wcpcpy(wchar_t* _wdest, const wchar_t* _wsrc) noexcept;
    extern wchar_t* wcsncpy(wchar_t* _wdest, const wchar_t* _wsrc, size_t _size) noexcept;
    extern wchar_t* wcpncpy(wchar_t* _wdest, const wchar_t* _wsrc, size_t _size) noexcept;
    extern void* memcpy(void* _dest, const void* _src, size_t _size) noexcept;
    extern void* memrcpy(void* _dest, const void* _src, size_t _size) noexcept;
    extern void* mempcpy(void* _dest, const void* _src, size_t _size) noexcept;
    extern void* memccpy(void* _dest, const void* _src, int _val, size_t _size) noexcept;
    extern void* memmove(void* _dest, const void* _src, size_t _size) noexcept;
    extern wchar_t* wmemcpy(wchar_t* _wdest, const wchar_t* _wsrc, size_t _size) noexcept;
    extern wchar_t* wmemrcpy(wchar_t* _wdest, const wchar_t* _wsrc, size_t _size) noexcept;
    extern wchar_t* wmempcpy(wchar_t* _wdest, const wchar_t* _wsrc, size_t _size) noexcept;
    extern wchar_t* wmemccpy(wchar_t* _wdest, const wchar_t* _wsrc, wchar_t _wval, size_t _size) noexcept;
    extern wchar_t* wmemmove(wchar_t* _wdest, const wchar_t* _wsrc, size_t _size) noexcept;

    // Concatenation
    extern char* strcat(char* _dest, const char* _src) noexcept;
    extern char* stpcat(char* _dest, const char* _src) noexcept;
    extern char* strncat(char* _dest, const char* _src, size_t _size) noexcept;
    extern char* stpncat(char* _dest, const char* _src, size_t _size) noexcept;
    extern wchar_t* wcscat(wchar_t* _wdest, const wchar_t* _wsrc) noexcept;
    extern wchar_t* wcpcat(wchar_t* _wdest, const wchar_t* _wsrc) noexcept;
    extern wchar_t* wcsncat(wchar_t* _wdest, const wchar_t* _wsrc, size_t _size) noexcept;
    extern wchar_t* wcpncat(wchar_t* _wdest, const wchar_t* _wsrc, size_t _size) noexcept;

    // Comparison
    extern int strncmp(const char* _cmp1, const char* _cmp2, size_t _size) noexcept;
    extern int strcmp(const char* _cmp1, const char* _cmp2) noexcept;
    extern int strcasecmp(const char* _cmp1, const char* _cmp2) noexcept;
    extern int strncasecmp(const char* _cmp1, const char* _cmp2, size_t _size) noexcept;
    extern int wcsncmp(const wchar_t* _cmp1, const wchar_t* _cmp2, size_t _size) noexcept;
    extern int wcscmp(const wchar_t* _cmp1, const wchar_t* _cmp2) noexcept;
    extern int wcscasecmp(const wchar_t* _cmp1, const wchar_t* _cmp2) noexcept;
    extern int wcsncasecmp(const wchar_t* _cmp1, const wchar_t* _cmp2, size_t _size) noexcept;
    extern int memcmp(const void* _cmp1, const void* _cmp2, size_t _size) noexcept;
    extern int wmemcmp(const wchar_t* _cmp1, const wchar_t* _cmp2, size_t _size) noexcept;

    // Searching
    extern char* strchr(char* _str, char _ch) noexcept;
    extern const char* strchr(const char* _str, char _ch) noexcept;
    extern char* strrchr(char* _str, char _ch) noexcept;
    extern const char* strrchr(const char* _str, char _ch) noexcept;
    extern char* strchrnul(char* _str, int _ch) noexcept;
    extern const char* strchrnul(const char* _str, int _ch) noexcept;
    extern size_t strcspn(const char* _src, const char* _pat) noexcept;
    extern char* strpbrk(char* _src, const char* _pat) noexcept;
    extern const char* strpbrk(const char* _src, const char* _pat) noexcept;
    extern size_t strspn(const char* _src, const char* _pat) noexcept;
    extern char* strstr(char* _src, const char* _pat) noexcept;
    extern const char* strstr(const char* _src, const char* _pat) noexcept;
    extern char* strcasestr(char* _cmp1, const char* _cmp2) noexcept;
    extern const char* strcasestr(const char* _cmp1, const char* _cmp2) noexcept;
    extern wchar_t* wcschr(wchar_t* _wstr, wchar_t _wch) noexcept;
    extern const wchar_t* wcschr(const wchar_t* _wstr, wchar_t _wch) noexcept;
    extern wchar_t* wcsrchr(wchar_t* _wstr, wchar_t _wch) noexcept;
    extern const wchar_t* wcsrchr(const wchar_t* _wstr, wchar_t _wch) noexcept;
    extern wchar_t* wcschrnul(wchar_t* _wstr, wchar_t _wch) noexcept;
    extern const wchar_t* wcschrnul(const wchar_t* _wstr, wchar_t _wch) noexcept;
    extern size_t wcscspn(const wchar_t* _wsrc, const wchar_t* _wpat) noexcept;
    extern wchar_t* wcspbrk(wchar_t* _wsrc, const wchar_t* _wpat) noexcept;
    extern const wchar_t* wcspbrk(const wchar_t* _wsrc, const wchar_t* _wpat) noexcept;
    extern size_t wcsspn(const wchar_t* _wsrc, const wchar_t* _wpat) noexcept;
    extern wchar_t* wcsstr(wchar_t* _wsrc, const wchar_t* _wpat) noexcept;
    extern wchar_t* wcscasestr(wchar_t* _cmp1, const wchar_t* _cmp2) noexcept;
    extern const wchar_t* wcscasestr(const wchar_t* _cmp1, const wchar_t* _cmp2) noexcept;
    extern const wchar_t* wcsstr(const wchar_t* _wsrc, const wchar_t* _wpat) noexcept;
    extern void* memchr(void* _src, int _val, size_t _size) noexcept;
    extern const void* memchr(const void* _src, int _val, size_t _size) noexcept;
    extern void* memrchr(void* _src, int _val, size_t _size) noexcept;
    extern const void* memrchr(const void* _src, int _val, size_t _size) noexcept;
    extern void* memmem(void* _src, size_t _slen, const void* _pat, size_t _plen) noexcept;
    extern const void* memmem(const void* _src, size_t _slen, const void* _pat, size_t _plen) noexcept;
    extern wchar_t* wmemchr(wchar_t* _wsrc, wchar_t _wval, size_t _size) noexcept;
    extern const wchar_t* wmemchr(const wchar_t* _wsrc, wchar_t _wval, size_t _size) noexcept;

    // Fill
    extern void* memset(void* _mem, int _val, size_t _size) noexcept;
    extern wchar_t* wmemset(wchar_t* _mem, wchar_t _wval, size_t _size) noexcept;

    // split
    extern char* strsep(char** _str, const char* _token) noexcept;

    // extern char* strfry(char* _str) noexcept;

  }
}

}

#endif // ! ___UTILITY__STANDARD__LIBRARY__CSTDING___
