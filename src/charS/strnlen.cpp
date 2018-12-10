
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    size_t strnlen(const char* _str, size_t _mlen) noexcept
    {
      size_t __len = 0U;
      for( ; *_str && _mlen; ++_str, ++__len, --_mlen)
      { }
      return __len;
    }

  }
}
