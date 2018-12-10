
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    size_t wcsnlen(const wchar_t* _wstr, size_t _mlen) noexcept
    {
      size_t __len = 0U;
      for( ; *_wstr && _mlen; ++_wstr, ++__len, --_mlen)
      { }
      return __len;
    }

  }
}
