
#ifndef ___UTILITY__BUILTIN__FUNCTION___
#define ___UTILITY__BUILTIN__FUNCTION___

namespace utility
{
  namespace _builtin
  {
    extern bool _add_overflow(
      unsigned char _x, unsigned char _y, unsigned char* _val
    ) noexcept;
    extern bool _add_overflow(
      unsigned short _x, unsigned short _y, unsigned short* _val
    ) noexcept;
    extern bool _add_overflow(
      unsigned int _x, unsigned int _y, unsigned int* _val
    ) noexcept;
    extern bool _add_overflow(
      unsigned long _x, unsigned long _y, unsigned long* _val
    ) noexcept;
    extern bool _add_overflow(
      unsigned long long _x, unsigned long long _y, unsigned long long* _val
    ) noexcept;

    extern unsigned long _mul_overflow_word(
      unsigned long _x, unsigned long _y, unsigned long* _val
    ) noexcept;
    extern unsigned long long _mul_overflow_word(
      unsigned long long _x, unsigned long long _y, unsigned long long* _val
    ) noexcept;

    extern int _nlz(unsigned char _val) noexcept;
    extern int _nlz(unsigned short _val) noexcept;
    extern int _nlz(unsigned int _val) noexcept;
    extern int _nlz(unsigned long _val) noexcept;
    extern int _nlz(unsigned long long _val) noexcept;

    extern int _ntz(unsigned char _val) noexcept;
    extern int _ntz(unsigned short _val) noexcept;
    extern int _ntz(unsigned int _val) noexcept;
    extern int _ntz(unsigned long _val) noexcept;
    extern int _ntz(unsigned long long _val) noexcept;

    extern int _popcount(unsigned char _val) noexcept;
    extern int _popcount(unsigned short _val) noexcept;
    extern int _popcount(unsigned int _val) noexcept;
    extern int _popcount(unsigned long _val) noexcept;
    extern int _popcount(unsigned long long _val) noexcept;

    extern unsigned char _breverse(unsigned char _val) noexcept;
    extern unsigned short _breverse(unsigned short _val) noexcept;
    extern unsigned int _breverse(unsigned int _val) noexcept;
    extern unsigned long _breverse(unsigned long _val) noexcept;
    extern unsigned long long _breverse(unsigned long long _val) noexcept;

    extern unsigned char _lex_next(unsigned char _val) noexcept;
    extern unsigned short _lex_next(unsigned short _val) noexcept;
    extern unsigned int _lex_next(unsigned int _val) noexcept;
    extern unsigned long _lex_next(unsigned long _val) noexcept;
    extern unsigned long long _lex_next(unsigned long long _val) noexcept;

    extern unsigned char _lex_prev(unsigned char _val) noexcept;
    extern unsigned short _lex_prev(unsigned short _val) noexcept;
    extern unsigned int _lex_prev(unsigned int _val) noexcept;
    extern unsigned long _lex_prev(unsigned long _val) noexcept;
    extern unsigned long long _lex_prev(unsigned long long _val) noexcept;
  }
}

#endif // ! ___UTILITY__BUILTIN__FUNCTION___
