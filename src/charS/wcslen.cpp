
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    size_t wcslen(const wchar_t* _wstr) noexcept
    {
      size_t __len = 0U;
      for(; *_wstr; ++_wstr, ++__len)
      { }
      return __len;
    }

  }
}
