
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    wchar_t* wcschr(wchar_t* _wstr, wchar_t _wch) noexcept
    {
      if(_wstr != nullptr)
      {
        for(; *_wstr; ++_wstr)
        {
          if(*_wstr == _wch)
          { return _wstr;}
        }
        if(*_wstr == _wch)
        { return _wstr;}
      }
      return nullptr;
    }
    const wchar_t* wcschr(const wchar_t* _wstr, wchar_t _wch) noexcept
    {
      if(_wstr != nullptr)
      {
        for(; *_wstr; ++_wstr)
        {
          if(*_wstr == _wch)
          { return _wstr;}
        }
        if(*_wstr == _wch)
        { return _wstr;}
      }
      return nullptr;
    }

  }
}
