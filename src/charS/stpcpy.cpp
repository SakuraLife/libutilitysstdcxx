
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    char* stpcpy(char* _dest, const char* _src) noexcept
    {
      if(_dest != nullptr && _src != nullptr)
      {
        for(; *_src;)
        { *_dest++ = *_src++;}
        *_dest = '\0';
      }
      return _dest;
    }

  }
}
