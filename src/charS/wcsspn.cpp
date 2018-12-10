
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    size_t wcsspn(const wchar_t* _wsrc, const wchar_t* _wpat) noexcept
    {
      size_t __i = 0;
      if(_wsrc != nullptr && _wpat != nullptr)
      {
        for(; *_wsrc;)
        {
          const wchar_t* __wpat = _wpat;
          for(; *__wpat;)
          {
            if(*__wpat++ == *_wsrc)
            { ++__i; break;}
          }
          ++_wsrc;
        }
      }
      return __i;
    }

  }
}
