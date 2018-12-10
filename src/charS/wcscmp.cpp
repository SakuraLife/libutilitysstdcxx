
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    int wcscmp(const wchar_t* _cmp1, const wchar_t* _cmp2) noexcept
    {
      size_t __size1 = wcslen(_cmp1);
      size_t __size2 = wcslen(_cmp2);
      size_t __size = __size1 < __size2 ? __size1 : __size2;
      int x = wcsncmp(_cmp1, _cmp2, static_cast<size_t>(__size));
      return x ? x : (__size1==__size2 ? 0 :( __size1<__size2 ? -1 : 1));
    }

  }
}
