
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    char* stpcat(char* _dest, const char* _src) noexcept
    {
      if(_dest != nullptr && _src != nullptr)
      {
        _dest = strend(_dest);
        for(; *_src;)
        { *_dest++ = *_src++;}
        *_dest = '\0';
      }
      return _dest;
    }

  }
}
