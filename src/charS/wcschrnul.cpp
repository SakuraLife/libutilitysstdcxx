
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    wchar_t* wcschrnul(wchar_t* _wstr, wchar_t _wch) noexcept
    {
      if(_wstr != nullptr)
      {
        for(; *_wstr;)
        {
          if(*_wstr++ == _wch)
          { return _wstr-1;}
        }
        if(*_wstr == _wch)
        { return _wstr;}
      }
      return _wstr;
    }
    const wchar_t* wcschrnul(const wchar_t* _wstr, wchar_t _wch) noexcept
    {
      if(_wstr != nullptr)
      {
        for(; *_wstr;)
        {
          if(*_wstr++ == _wch)
          { return _wstr-1;}
        }
        if(*_wstr == _wch)
        { return _wstr;}
      }
      return _wstr;
    }

  }
}
