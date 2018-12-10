
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    char* strrchr(char* _str, char _ch) noexcept
    {
      if(_str != nullptr)
      {
        char* __end = strend(_str);
        for(; __end >= _str;)
        {
          if(*__end-- == _ch)
          { return __end+1;}
        }
      }
      return _str;
    }
    const char* strrchr(const char* _str, char _ch) noexcept
    {
      if(_str != nullptr)
      {
        const char* __end = strend(_str);
        for(; __end >= _str;)
        {
          if(*__end-- == _ch)
          { return __end+1;}
        }
      }
      return nullptr;
    }

  }
}
