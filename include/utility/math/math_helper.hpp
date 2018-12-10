
#ifndef __UTILITY_MATH_MATH_HELPER__
#define __UTILITY_MATH_MATH_HELPER__

#include<utility/config/utility_config.hpp>

namespace utility
{
  namespace algorithm
  { }

  namespace math
  {
    namespace helper
    {
      typedef unsigned char         _uc;
      typedef unsigned short        _us;
      typedef unsigned int          _ui;
      typedef unsigned long         _ul;
      typedef unsigned long long    _ull;
      typedef signed char           _sc;
      typedef signed short          _ss;
      typedef signed int            _si;
      typedef signed long           _sl;
      typedef signed long long      _sll;

      namespace
      {
        template<unsigned long long _N>
        struct _bits
        {
          constexpr static int bits = _bits<_N/2>::bits + 1;
        };
        template<>
        struct _bits<0>
        {
          constexpr static int bits = 0;
        };

        template<unsigned long long _Bits>
        struct _bits_10
        {
          constexpr static _si bits10 = _Bits * 643L / 2136;;
        };

        constexpr unsigned char         _muc  = ~_uc{0U};
        constexpr unsigned short        _mus  = ~_us{0U};
        constexpr unsigned int          _mui  = ~_ui{0U};
        constexpr unsigned long         _mul  = ~_ul{0U};
        constexpr unsigned long long    _mull = ~_ull{0U};

        constexpr signed char           _msc  = static_cast<_sc>(_muc >> 1);
        constexpr signed short          _mss  = static_cast<_ss>(_mus >> 1);
        constexpr signed int            _msi  = static_cast<_si>(_mui >> 1);
        constexpr signed long           _msl  = static_cast<_sl>(_mul >> 1);
        constexpr signed long long      _msll = static_cast<_sll>(_mull >> 1);

        constexpr unsigned char         _suc  = _uc{0U};
        constexpr unsigned short        _sus  = _us{0U};
        constexpr unsigned int          _sui  = _ui{0U};
        constexpr unsigned long         _sul  = _ul{0U};
        constexpr unsigned long long    _sull = _ull{0U};

        constexpr signed char           _ssc  = -_msc - 1;
        constexpr signed short          _sss  = -_mss - 1;
        constexpr signed int            _ssi  = -_msi - 1;
        constexpr signed long           _ssl  = -_msl - 1;
        constexpr signed long long      _ssll = -_msll - 1;

        constexpr int          _buc  = _bits<_muc>::bits;
        constexpr int          _bus  = _bits<_mus>::bits;
        constexpr int          _bui  = _bits<_mui>::bits;
        constexpr int          _bul  = _bits<_mul>::bits;
        constexpr int          _bull = _bits<_mull>::bits;
        constexpr int          _bsc  = _buc - 1;
        constexpr int          _bss  = _bus - 1;
        constexpr int          _bsi  = _bui - 1;
        constexpr int          _bsl  = _bul - 1;
        constexpr int          _bsll = _bull - 1;

        constexpr unsigned int          _char_bits = _bul / sizeof(_ul);
      }
    }
    using namespace algorithm;
  }

  using math::helper::_char_bits;
}

#endif // ! __UTILITY_MATH_MATH_HELPER__
