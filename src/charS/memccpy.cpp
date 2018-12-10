
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    void* memccpy(void* _dest, const void* _src, int _val, size_t _size) noexcept
    {
      if(_size && _dest != nullptr && _src != nullptr)
      {
        unsigned char* __dest = static_cast<unsigned char*>(_dest);
        const unsigned char* __src = static_cast<const unsigned char*>(_src);
        unsigned char __val = static_cast<unsigned char>(_val);
        for(; _size; --_size)
        {
          if((*__dest++ = *__src++) == __val)
          { return __dest;}
        }
        return nullptr;
      }
      return _dest;
    }

  }
}
