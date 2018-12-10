
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    wchar_t* wcsstr(wchar_t* _wsrc, const wchar_t* _wpat) noexcept
    {
      if(_wpat == nullptr)
      { return _wsrc;}

      if(_wsrc != nullptr)
      {
        size_t __slen = wcslen(_wsrc);
        size_t __plen = wcslen(_wpat);
        if(__slen < __plen)
        { return nullptr;}
        size_t __len = __slen - __plen+1;
        for(; __len; --__len)
        {
          if((*_wsrc == * _wpat) && wcsncmp(_wsrc, _wpat, __plen) == 0)
          { return _wsrc;}
          ++_wsrc;
        }
      }
      return nullptr;
    }
    const wchar_t* wcsstr(const wchar_t* _wsrc, const wchar_t* _wpat) noexcept
    {
      if(_wpat == nullptr)
      { return _wsrc;}

      if(_wsrc != nullptr)
      {
        size_t __slen = wcslen(_wsrc);
        size_t __plen = wcslen(_wpat);
        if(__slen < __plen)
        { return nullptr;}
        size_t __len = __slen - __plen+1;
        for(; __len; --__len)
        {
          if((*_wsrc == * _wpat) && wcsncmp(_wsrc, _wpat, __plen) == 0)
          { return _wsrc;}
          ++_wsrc;
        }
      }
      return nullptr;
    }

  }
}
