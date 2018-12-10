
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    char* strncpy(char* _dest, const char* _src, size_t _size) noexcept
    {
      if(_size && _dest != nullptr && _src != nullptr)
      {
        char* __dest = _dest;
        for(; _size && *_src; --_size)
        { *__dest++ = *_src++;}
        *__dest = '\0';
      }
      return _dest;
    }

  }
}
