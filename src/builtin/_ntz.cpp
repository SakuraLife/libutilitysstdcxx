#include"builtin_function.h"


namespace
{
  template<int _Bits>
  struct __ntz
  {
    template<typename _T>
    static inline int aux(_T _val) noexcept
    {
      int __bits = _Bits;
      while(_val != 0)
      {
        --__bits;
        _val <<= 1;
      }
      return __bits;
    }
  };

  template<>
  struct __ntz<8>
  {
    template<typename _T>
    static inline int aux(_T _val) noexcept
    {
      if(_val == 0)
      { return 8;}

      int __bits = 1;
      if((_val & 0xfU) == 0U)
      {
        __bits += 4;
        _val >>= 4;
      }
      if((_val & 0x3U) == 0U)
      {
        __bits += 2;
        _val >>= 2;
      }

      return __bits - static_cast<int>(_val & 0x1U);
    }
  };

  template<>
  struct __ntz<16>
  {
    template<typename _T>
    static inline int aux(_T _val) noexcept
    {
      if(_val == 0)
      { return 16;}

      int __bits = 1;
      if((_val & 0xffU) == 0U)
      {
        __bits += 8;
        _val >>= 8;
      }
      if((_val & 0xfU) == 0U)
      {
        __bits += 4;
        _val >>= 4;
      }
      if((_val & 0x3U) == 0U)
      {
        __bits += 2;
        _val >>= 2;
      }

      return __bits - static_cast<int>(_val & 0x1U);
    }
  };

  template<>
  struct __ntz<32>
  {
    template<typename _T>
    static inline int aux(_T _val) noexcept
    {
      if(_val == 0)
      { return 32;}

      int __bits = 1;
      if((_val & 0xffffUL) == 0U)
      {
        __bits += 16;
        _val >>= 16;
      }
      if((_val & 0xffUL) == 0U)
      {
        __bits += 8;
        _val >>= 8;
      }
      if((_val & 0xfUL) == 0U)
      {
        __bits += 4;
        _val >>= 4;
      }
      if((_val & 0x3UL) == 0U)
      {
        __bits += 2;
        _val >>= 2;
      }

      return __bits - static_cast<int>(_val & 0x1UL);
    }
  };

  template<>
  struct __ntz<64>
  {
    template<typename _T>
    static inline int aux(_T _val) noexcept
    {
      if(_val == 0)
      { return 64;}

      int __bits = 1;
      if((_val & 0xffffffffULL) == 0U)
      {
        __bits += 16;
        _val >>= 16;
      }
      if((_val & 0xffffULL) == 0U)
      {
        __bits += 16;
        _val >>= 16;
      }
      if((_val & 0xffULL) == 0U)
      {
        __bits += 8;
        _val >>= 8;
      }
      if((_val & 0xfULL) == 0U)
      {
        __bits += 4;
        _val >>= 4;
      }
      if((_val & 0x3ULL) == 0U)
      {
        __bits += 2;
        _val >>= 2;
      }

      return __bits - static_cast<int>(_val & 0x1ULL);
    }
  };
}

__utility_globalspace_start(utility)
int _builtin::_ntz(unsigned char _val) noexcept
{ return _buc - __ntz<_buc>::aux(_val);}
int _builtin::_ntz(unsigned short _val) noexcept
{ return _bus - __ntz<_bus>::aux(_val);}
int _builtin::_ntz(unsigned int _val) noexcept
{ return _bui - __ntz<_bui>::aux(_val);}
int _builtin::_ntz(unsigned long _val) noexcept
{ return _bul - __ntz<_bul>::aux(_val);}
int _builtin::_ntz(unsigned long long _val) noexcept
{ return _bull - __ntz<_bull>::aux(_val);}
__utility_globalspace_end(utility)
