
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    int wcsncmp(const wchar_t* _cmp1, const wchar_t* _cmp2, size_t _size) noexcept
    {
      if(_size)
      {
        for(; _size; ++_cmp1, ++_cmp2, --_size)
        {
          if(*_cmp1 != *_cmp2)
          { return *_cmp1 < *_cmp2 ? -1 : 1;}
        }
      }
      return 0;
    }

  }
}
