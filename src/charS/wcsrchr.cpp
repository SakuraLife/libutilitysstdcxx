
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    wchar_t* wcsrchr(wchar_t* _wstr, wchar_t _wch) noexcept
    {
      if(_wstr != nullptr)
      {
        wchar_t* __wend = wcsend(_wstr);
        for(; __wend >= _wstr; --__wend)
        {
          if(*__wend == _wch)
          { return __wend;}
        }
      }
      return nullptr;
    }
    const wchar_t* wcsrchr(const wchar_t* _wstr, wchar_t _wch) noexcept
    {
      if(_wstr != nullptr)
      {
        const wchar_t* __wend = wcsend(_wstr);
        for(; __wend >= _wstr; --__wend)
        {
          if(*__wend == _wch)
          { return __wend;}
        }
      }
      return nullptr;
    }

  }
}
