
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    wchar_t* wmemrcpy(wchar_t* _wdest, const wchar_t* _wsrc, size_t _size) noexcept
    {
      if(_size && _wdest != nullptr && _wsrc != nullptr)
      {
        wchar_t* __wdest = _wdest+_size-1;
        const wchar_t* __wsrc = _wsrc+_size-1;
        for(; _size; --_size)
        { *__wdest-- = *__wsrc--;}
      }
      return _wdest;
    }

  }
}
