
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    wchar_t* wcpcat(wchar_t* _wdest, const wchar_t* _wsrc) noexcept
    {
      if(_wdest != nullptr && _wsrc != nullptr)
      {
        _wdest = wcsend(_wdest);
        for(; *_wsrc;)
        { *_wdest++ = *_wsrc++;}
        *_wdest = '\0';
      }
      return _wdest;
    }

  }
}
