
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    char* strcasestr(char* _src, const char* _pat) noexcept
    {
      if(_pat == nullptr)
      { return _src;}

      if(_src != nullptr)
      {
        size_t __slen = strlen(_src);
        size_t __plen = strlen(_pat);
        if(__slen < __plen)
        { return nullptr;}
        size_t __len = __slen - __plen+1;
        for(; __len; --__len)
        {
          if((*_src == * _pat) && strncasecmp(_src, _pat, __plen) == 0)
          { return _src;}
          ++_src;
        }
      }
      return nullptr;
    }
    const char* strcasestr(const char* _src, const char* _pat) noexcept
    {
      if(_pat == nullptr)
      { return _src;}

      if(_src != nullptr)
      {
        size_t __slen = strlen(_src);
        size_t __plen = strlen(_pat);
        if(__slen < __plen)
        { return nullptr;}
        size_t __len = __slen - __plen+1;
        for(; __len; --__len)
        {
          if((*_src == * _pat) && strncasecmp(_src, _pat, __plen) == 0)
          { return _src;}
          ++_src;
        }
      }
      return nullptr;
    }

  }
}
