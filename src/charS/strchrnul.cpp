
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    char* strchrnul(char* _str, int _ch) noexcept
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
      return _str;
    }
    const char* strchrnul(const char* _str, int _ch) noexcept
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
      return _str;
    }

  }
}
