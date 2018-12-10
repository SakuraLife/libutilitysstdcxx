
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    char* stpncpy(char* _dest, const char* _src,size_t _size) noexcept
    {
      if(_size && _dest != nullptr && _src != nullptr)
      {
        for(; _size && *_src; --_size)
        { *_dest++ = *_src++;}
        *_dest = '\0';
      }
      return _dest;
    }

  }
}
