
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    wchar_t* wmemchr(wchar_t* _wsrc, wchar_t _wval, size_t _size) noexcept
    {
      if(_wsrc != nullptr)
      {
        for(; _size; --_size)
        {
          if(*_wsrc++ == _wval)
          { return (_wsrc-1);}
        }
      }
      return nullptr;
    }
    const wchar_t* wmemchr(const wchar_t* _wsrc, wchar_t _wval, size_t _size) noexcept
    {
      if(_wsrc != nullptr)
      {
        for(; _size; --_size)
        {
          if(*_wsrc++ == _wval)
          { return (_wsrc-1);}
        }
      }
      return nullptr;
    }

  }
}
