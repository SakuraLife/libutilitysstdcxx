
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    wchar_t* wcspbrk(wchar_t* _wsrc, const wchar_t* _wpat) noexcept
    {
      if(_wpat == nullptr)
      { return _wsrc;}

      if(_wsrc != nullptr)
      {
        for(; *_wsrc;)
        {
          const wchar_t* __wpat = _wpat;
          for(; *__wpat;)
          {
            if(*__wpat++ == *_wsrc)
            { return _wsrc;}
          }
          ++_wsrc;
        }
      }
      return nullptr;
    }
    const wchar_t* wcspbrk(const wchar_t* _wsrc, const wchar_t* _wpat) noexcept
    {
      if(_wpat == nullptr)
      { return _wsrc;}

      if(_wsrc != nullptr)
      {
        for(; *_wsrc;)
        {
          const wchar_t* __wpat = _wpat;
          for(; *__wpat;)
          {
            if(*__wpat++ == *_wsrc)
            { return _wsrc;}
          }
          ++_wsrc;
        }
      }
      return nullptr;
    }

  }
}
