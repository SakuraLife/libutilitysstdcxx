#include"builtin_function.h"

namespace
{
  template<int _Bits>
  struct __nlz
  {
    template<typename _T>
    static inline int aux(_T _val) noexcept
    {
      int __bits = _Bits;
      int __hbits = _Bits / 2;
      do
      {
        _T __tmp = _val >> __hbits;
        if(__tmp != 0)
        {
          _val = __tmp;
          __hbits >>= 1;
        }
      }
      while(__hbits != 0);
      return __bits;
    }
  };

  template<>
  struct __nlz<8>
  {
    template<typename _T>
    static inline int aux(_T _val) noexcept
    {
      if(_val == 0)
      { return 8;}

      int __bits = 0;
      if(_val <= 0xfU)
      {
        __bits += 4;
        _val <<= 4;
      }
      if(_val <= 0x3fU)
      {
        __bits += 2;
        _val <<= 2;
      }
      if(_val <= 0x7fU)
      { __bits += 1;}

      return __bits;
    }
  };

  template<>
  struct __nlz<16>
  {
    template<typename _T>
    static inline int aux(_T _val) noexcept
    {
      if(_val == 0)
      { return 16;}

      int __bits = 0;
      if(_val <= 0xffU)
      {
        __bits += 8;
        _val <<= 8;
      }
      if(_val <= 0xfffU)
      {
        __bits += 4;
        _val <<= 4;
      }
      if(_val <= 0x3fffU)
      {
        __bits += 2;
        _val <<= 2;
      }
      if(_val <= 0x7fffU)
      { __bits += 1;}

      return __bits;
    }
  };

  template<>
  struct __nlz<32>
  {
    template<typename _T>
    static inline int aux(_T _val) noexcept
    {
      if(_val == 0)
      { return 32;}

      int __bits = 0;
      if(_val <= 0xffffUL)
      {
        __bits += 16;
        _val <<= 16;
      }
      if(_val <= 0xffffffUL)
      {
        __bits += 8;
        _val <<= 8;
      }
      if(_val <= 0xfffffffUL)
      {
        __bits += 4;
        _val <<= 4;
      }
      if(_val <= 0x3fffffffUL)
      {
        __bits += 2;
        _val <<= 2;
      }
      if(_val <= 0x7fffffffUL)
      { __bits += 1;}

      return __bits;
    }
  };

  template<>
  struct __nlz<64>
  {
    template<typename _T>
    static inline int aux(_T _val) noexcept
    {
      if(_val == 0)
      { return 64;}

      int __bits = 0;
      if(_val <= 0xffffffffULL)
      {
        __bits += 32;
        _val <<= 32;
      }
      if(_val <= 0xffffffffffffULL)
      {
        __bits += 16;
        _val <<= 16;
      }
      if(_val <= 0xffffffffffffffULL)
      {
        __bits += 8;
        _val <<= 8;
      }
      if(_val <= 0xfffffffffffffffULL)
      {
        __bits += 4;
        _val <<= 4;
      }
      if(_val <= 0x3fffffffffffffffULL)
      {
        __bits += 2;
        _val <<= 2;
      }
      if(_val <= 0x7fffffffffffffffUL)
      { __bits += 1;}

      return __bits;
    }
  };
}

__utility_globalspace_start(utility)
int _builtin::_nlz(unsigned char _val) noexcept
{ return __nlz<_buc>::aux(_val);}
int _builtin::_nlz(unsigned short _val) noexcept
{ return __nlz<_bus>::aux(_val);}
int _builtin::_nlz(unsigned int _val) noexcept
{ return __nlz<_bui>::aux(_val);}
int _builtin::_nlz(unsigned long _val) noexcept
{ return __nlz<_bul>::aux(_val);}
int _builtin::_nlz(unsigned long long _val) noexcept
{ return __nlz<_bull>::aux(_val);}
__utility_globalspace_end(utility)
