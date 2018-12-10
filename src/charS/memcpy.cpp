
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    void* memcpy(void* _dest, const void* _src, size_t _size) noexcept
    {
      if(_size && _dest != nullptr && _src != nullptr)
      {
        unsigned char* __dest = static_cast<unsigned char*>(_dest);
        const unsigned char* __src = static_cast<const unsigned char*>(_src);
        for(; _size; --_size)
        { *__dest++ = *__src++;}
      }
      return _dest;
    }

  }
}
