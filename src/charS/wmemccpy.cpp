
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    wchar_t* wmemccpy(wchar_t* _wdest, const wchar_t* _wsrc, wchar_t _wval, size_t _size) noexcept
    {
      if(_size && _wdest != nullptr && _wsrc != nullptr)
      {
        for(; _size; --_size)
        {
          if((*_wdest++ = *_wsrc++) == _wval)
          { return _wdest;}
        }
        return nullptr;
      }
      return _wdest;
    }

  }
}
