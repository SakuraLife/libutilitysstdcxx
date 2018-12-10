
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    void* memset(void* _mem, int _val, size_t _size) noexcept
    {
      if(_size && _mem != nullptr)
      {
        unsigned char* __src = static_cast<unsigned char*>(_mem);
        unsigned char __val = static_cast<unsigned char>(_val);
        for(; _size; --_size)
        { *__src++ = __val;}
      }
      return _mem;
    }

  }
}
