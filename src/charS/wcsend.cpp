
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    wchar_t* wcsend(wchar_t* _wstr) noexcept
    {
      if(_wstr != nullptr)
      {
        for(; *_wstr;)
        { ++_wstr;}
      }
      return _wstr;
    }
    const wchar_t* wcsend(const wchar_t* _wstr) noexcept
    {
      if(_wstr != nullptr)
      {
        for(; *_wstr;)
        { ++_wstr;}
      }
      return _wstr;
    }

  }
}
