
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    char* strcat(char* _dest, const char* _src) noexcept
    {
      if(_dest != nullptr && _src != nullptr)
      {
        char* __dest = strend(_dest);
        for(; *_src;)
        { *__dest++ = *_src++;}
        *__dest = '\0';
      }
      return _dest;
    }

  }
}
