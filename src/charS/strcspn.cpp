
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    size_t strcspn(const char* _src, const char* _pat) noexcept
    {
      if(_src != nullptr && _pat != nullptr)
      {
        const char* __src = _src;
        for(; *__src;)
        {
          const char* __pat = _pat;
          for(; *__pat;)
          {
            if(*__pat++ == *__src)
            { return static_cast<size_t>(__src - _src);}
          }
          ++__src;
        }
        return static_cast<size_t>(__src - _src);
      }
      return 0;
    }

  }
}
