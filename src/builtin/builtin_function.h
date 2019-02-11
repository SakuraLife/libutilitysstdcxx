
// #include<utility/config/utility_config.hpp>
#include<utility/config/builtin_function.hpp>

typedef unsigned char _uc;
typedef unsigned short _us;
typedef unsigned int _ui;
typedef unsigned long _ul;
typedef unsigned long long _ull;

namespace
{
  constexpr _us __bits(_ull _val, _us _now) noexcept
  { return _val ? __bits(_val >> 1U, _now + 1) : _now;}

  template<unsigned long long _N>
  struct _bits
  {
    constexpr static unsigned short bits = _bits<_N/2>::bits + 1;
  };
  template<>
  struct _bits<0>
  {
    constexpr static unsigned short bits = 0;
  };

  constexpr unsigned char        _muc  = static_cast<_uc>(~_uc{0U});
  constexpr unsigned short       _mus  = static_cast<_us>(~_us{0U});
  constexpr unsigned int         _mui  = ~_ui{0U};
  constexpr unsigned long        _mul  = ~_ul{0UL};
  constexpr unsigned long long   _mull = ~_ull{0ULL};

  constexpr unsigned char        _hbuc  = static_cast<_uc>(~(_muc >> 1U));
  constexpr unsigned short       _hbus  = static_cast<_us>(~(_mus >> 1U));
  constexpr unsigned int         _hbui  = ~(_mui >> 1U);
  constexpr unsigned long        _hbul  = ~(_mul >> 1U);
  constexpr unsigned long long   _hbull = ~(_mull >> 1U);

  constexpr unsigned short       _buc = _bits<_muc>::bits;
  constexpr unsigned short       _bus = _bits<_mus>::bits;
  constexpr unsigned short       _bui = _bits<_mui>::bits;
  constexpr unsigned short       _bul = _bits<_mul>::bits;
  constexpr unsigned short       _bull = _bits<_mull>::bits;

  constexpr unsigned char        _char_bits = _bul / sizeof(_ul);

  constexpr unsigned char        _luc  = _muc >> (_buc / 2);
  constexpr unsigned short       _lus  = _mus >> (_bus / 2);
  constexpr unsigned int         _lui  = _mui >> (_bui / 2);
  constexpr unsigned long        _lul  = _mul >> (_bul / 2);
  constexpr unsigned long long   _lull = _mull >> (_bull / 2);

}
