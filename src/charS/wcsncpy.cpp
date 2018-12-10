
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    wchar_t* wcsncpy(wchar_t* _wdest, const wchar_t* _wsrc, size_t _size) noexcept
    {
      if(_size && _wdest != nullptr && _wsrc != nullptr)
      {
        wchar_t* __dest = _wdest;
        for(; _size && *_wsrc; --_size)
        { *__dest++ = *_wsrc++;}
        *__dest = '\0';
      }
      return _wdest;
    }

  }
}
