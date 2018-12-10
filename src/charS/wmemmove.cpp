
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    wchar_t* wmemmove(wchar_t* _wdest, const wchar_t* _wsrc, size_t _size) noexcept
    {
      if(_size && _wdest != nullptr && _wsrc != nullptr && _wdest != _wsrc)
      {
        if(_wdest > _wsrc)
        { wmemrcpy(_wdest, _wsrc, _size);}
        else
        { wmemcpy(_wdest, _wsrc, _size);}
      }
      return _wdest;
    }

  }
}
