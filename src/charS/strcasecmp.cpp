
#include<utility/sstd/cstring.hpp>
#include<utility/sstd/cctype.hpp>

namespace utility
{
  namespace sstd
  {
    int strcasecmp(const char* _cmp1, const char* _cmp2) noexcept
    {
      size_t __size1 = strlen(_cmp1);
      size_t __size2 = strlen(_cmp2);
      size_t __size = __size1 < __size2 ? __size1 : __size2;
      int x = strncasecmp(_cmp1, _cmp2, static_cast<size_t>(__size));
      return x ? x : (__size1==__size2 ? 0 :( __size1<__size2 ? -1 : 1));
    }

  }
}
