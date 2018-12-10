
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    char* strchr(char* _str, char _ch) noexcept
    {
      if(_str != nullptr)
      {
        for(; *_str;)
        {
          if(*_str++ == _ch)
          { return _str-1;}
        }
        if(*_str == _ch)
        { return _str;}
      }
      return nullptr;
    }
    const char* strchr(const char* _str, char _ch) noexcept
    {
      if(_str != nullptr)
      {
        for(; *_str;)
        {
          if(*_str++ == _ch)
          { return _str-1;}
        }
        if(*_str == _ch)
        { return _str;}
      }
      return nullptr;
    }

  }
}
