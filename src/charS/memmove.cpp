
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    void* memmove(void* _dest, const void* _src, size_t _size) noexcept
    {
      if(_size && _dest != nullptr && _src != nullptr && _dest != _src)
      {
        if(_dest > _src)
        { memrcpy(_dest, _src, _size);}
        else
        { memcpy(_dest, _src, _size);}
      }
      return _dest;
    }

  }
}
