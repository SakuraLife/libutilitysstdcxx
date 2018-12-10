
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    char* strend(char* _str) noexcept
    {
      if(_str != nullptr)
      {
        for(; *_str;)
        { ++_str;}
      }
      return _str;
    }
    const char* strend(const char* _str) noexcept
    {
      if(_str != nullptr)
      {
        for(; *_str;)
        { ++_str;}
      }
      return _str;
    }

  }
}
