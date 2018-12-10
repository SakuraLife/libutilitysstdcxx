
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    wchar_t* wcscat(wchar_t* _wdest, const wchar_t* _wsrc) noexcept
    {
      if(_wdest != nullptr && _wsrc != nullptr)
      {
        wchar_t* __dest = wcsend(_wdest);
        for(; *_wsrc;)
        { *__dest++ = *_wsrc++;}
        *__dest = '\0';
      }
      return _wdest;
    }

  }
}
