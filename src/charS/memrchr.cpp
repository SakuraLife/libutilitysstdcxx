
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    void* memrchr(void* _src, int _val, size_t _size) noexcept
    {
      if(!_size)
      { return _src;}

      if(_src != nullptr)
      {
        unsigned char* __src = static_cast<unsigned char*>(_src)+_size-1;
        unsigned char __val = static_cast<unsigned char>(_val);
        for(; _size; --_size)
        {
          if(*__src-- == __val)
          { return static_cast<void*>(__src+1);}
        }
      }
      return nullptr;
    }
    const void* memrchr(const void* _src, int _val, size_t _size) noexcept
    {
      if(!_size)
      { return _src;}

      if(_src != nullptr)
      {
        const unsigned char* __src = static_cast<const unsigned char*>(_src)+_size-1;
        unsigned char __val = static_cast<unsigned char>(_val);
        for(; _size; --_size)
        {
          if(*__src-- == __val)
          { return static_cast<const void*>(__src+1);}
        }
      }
      return nullptr;
    }

  }
}
