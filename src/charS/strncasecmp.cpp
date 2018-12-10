
#include<utility/sstd/cstring.hpp>
#include<utility/sstd/cctype.hpp>

namespace utility
{
  namespace sstd
  {
    int strncasecmp(const char* _cmp1, const char* _cmp2, size_t _size) noexcept
    {
      if(_size)
      {
        for(; _size; ++_cmp1, ++_cmp2, --_size)
        {
          const char __ch1 = toupper(*_cmp1);
          const char __ch2 = toupper(*_cmp1);
          if(__ch1 != __ch2)
          { return __ch1 < __ch2 ? -1 : 1;}
        }
      }
      return 0;
    }

  }
}
