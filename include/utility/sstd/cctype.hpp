
#ifndef ___UTILITY__STANDARD__LIBRARY__CCTYPE___
#define ___UTILITY__STANDARD__LIBRARY__CCTYPE___

#include<utility/config/utility_config.hpp>

#define __CTYPE_UPPER     0X0001 // upper
#define __CTYPE_LOWER     0X0002 // lower
#define __CTYPE_DIGIT     0X0004 // dight
#define __CTYPE_CNTRL     0X0008 // cntrl
#define __CTYPE_PUNCT     0X0010 // punct
#define __CTYPE_XDIGHT    0X0020 // hex dight
#define __CTYPE_HSPACE    0X0040 // ' ' (0x20)
#define __CTYPE_SPACE     0X0080 // whitespace
#define __CTYPE_TAB       0X0100 // '\t' (0x9)

#define __CTYPE_ALPHA     (__CTYPE_UPPER | __CTYPE_LOWER)
#define __CTYPE_ALNUM     (__CTYPE_DIGIT | __CTYPE_ALPHA)
#define __CTYPE_GRAPH     (__CTYPE_ALNUM | __CTYPE_PUNCT)
#define __CTYPE_PRINT     (__CTYPE_GRAPH | __CTYPE_HSPACE)
#define __CTYPE_BLANK     (__CTYPE_HSPACE | __CTYPE_TAB)

extern "C++"
{

namespace utility
{
  namespace sstd
  {
    extern int cctype(int _ch) noexcept;

    extern int isalnum(int _ch) noexcept;
    extern int isalpha(int _ch) noexcept;
    extern int islower(int _ch) noexcept;
    extern int isupper(int _ch) noexcept;
    extern int isdigit(int _ch) noexcept;
    extern int isxdigit(int _ch) noexcept;
    extern int iscntrl(int _ch) noexcept;
    extern int isgraph(int _ch) noexcept;
    extern int isspace(int _ch) noexcept;
    extern int isblank(int _ch) noexcept;
    extern int isprint(int _ch) noexcept;
    extern int ispunct(int _ch) noexcept;

    extern int tolower(int _ch) noexcept;
    extern int toupper(int _ch) noexcept;
  }
}

}

#endif // ! ___UTILITY__STANDARD__LIBRARY__CCTYPE___
