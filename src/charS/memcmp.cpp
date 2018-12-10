
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    int memcmp(const void* _cmp1, const void* _cmp2, size_t _size) noexcept
    {
      if(_size)
      {
        const char* __ptr1 = static_cast<const char*>(_cmp1);
        const char* __ptr2 = static_cast<const char*>(_cmp2);
        for(; _size--; ++__ptr1, ++__ptr2)
        {
          if(*__ptr1 != *__ptr2)
          { return *__ptr1 - *__ptr2;}
        }
      }
      return 0;
    }

  }
}
