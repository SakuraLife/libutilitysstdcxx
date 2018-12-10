
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    wchar_t* wcpcpy(wchar_t* _wdest, const wchar_t* _wsrc) noexcept
    {
      if(_wdest != nullptr && _wsrc != nullptr)
      {
        for(; *_wsrc;)
        { *_wdest++ = *_wsrc++;}
        *_wdest = '\0';
      }
      return _wdest;
    }

  }
}
