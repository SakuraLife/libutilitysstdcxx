
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    wchar_t* wcpncpy(wchar_t* _wdest, const wchar_t* _wsrc, size_t _size) noexcept
    {
      if(_size && _wdest != nullptr && _wsrc != nullptr)
      {
        for(; *_wsrc && _size; --_size)
        { *_wdest = *_wsrc++;}
        *_wdest = '\0';
      }
      return _wdest;
    }

  }
}
