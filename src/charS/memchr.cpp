
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    void* memchr(void* _src, int _val, size_t _size) noexcept
    {
      if(_src != nullptr)
      {
        unsigned char* __src = static_cast<unsigned char*>(_src);
        unsigned char __val = static_cast<unsigned char>(_val);
        for(; _size; --_size)
        {
          if(*__src++ == __val)
          { return (__src-1);}
        }
      }
      return nullptr;
    }
    const void* memchr(const void* _src, int _val, size_t _size) noexcept
    {
      if(!_size)
      { return _src;}

      if(_src != nullptr)
      {
        const unsigned char* __src = static_cast<const unsigned char*>(_src);
        unsigned char __val = static_cast<unsigned char>(_val);
        for(; _size; --_size)
        {
          if(*__src++ == __val)
          { return static_cast<const void*>(__src-1);}
        }
      }
      return nullptr;
    }

  }
}
