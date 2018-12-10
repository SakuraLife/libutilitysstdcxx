
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    wchar_t* wmemcpy(wchar_t* _wdest, const wchar_t* _wsrc, size_t _size) noexcept
    {
      if(_size && _wdest != nullptr && _wsrc != nullptr)
      {
        wchar_t* _wcptr = _wdest;
        for(; _size; --_size)
        { *_wcptr++ = *_wsrc++;}
      }
      return _wdest;
    }

  }
}
