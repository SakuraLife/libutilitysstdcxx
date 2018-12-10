
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    size_t strlen(const char* _str) noexcept
    {
      size_t __len = 0U;
      for(; *_str; ++_str, ++__len)
      { }
      return __len;
    }

  }
}
