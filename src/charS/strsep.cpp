
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    char* strsep(char** _str, const char* _token) noexcept
    {
      if(*_str == nullptr)
      { return nullptr;}

      char* __src = *_str;
      for(; *__src; ++__src)
      {
        if(strchr(_token, *__src) == nullptr)
        {
          *__src = '\0';
          char* __res = *_str;
          *_str = __src+1;
          return __res;
        }
      }
      __src = *_str;
      *_str = nullptr;
      return __src;
    }

  }
}
