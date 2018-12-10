
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    size_t wcscspn(const wchar_t* _wsrc, const wchar_t* _wpat) noexcept
    {
      if(_wsrc != nullptr && _wpat != nullptr)
      {
        const wchar_t* __wsrc = _wsrc;
        for(; *__wsrc;)
        {
          const wchar_t* __wpat = _wpat;
          for(; *__wpat;)
          {
            if(*__wpat++ == *__wsrc)
            { return static_cast<size_t>(__wsrc - _wsrc);}
          }
          ++__wsrc;
        }
        return static_cast<size_t>(__wsrc - _wsrc);
      }
      return 0;
    }

  }
}
