
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    size_t strspn(const char* _src, const char* _pat) noexcept
    {
      size_t __i = 0;
      if(_src != nullptr && _pat != nullptr)
      {
        for(; *_src;)
        {
          const char* __pat = _pat;
          for(; *__pat;)
          {
            if(*__pat++ == *_src)
            { ++__i; break;}
          }
          ++_src;
        }
      }
      return __i;
    }

  }
}
