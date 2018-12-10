
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    char* strpbrk(char* _src, const char* _pat) noexcept
    {
      if(_pat == nullptr)
      { return _src;}

      if(_src != nullptr)
      {
        for(; *_src;)
        {
          const char* __pat = _pat;
          for(; *__pat;)
          {
            if(*__pat++ == *_src)
            { return _src;}
          }
          ++_src;
        }
      }
      return nullptr;
    }
    const char* strpbrk(const char* _src, const char* _pat) noexcept
    {
      if(_pat == nullptr)
      { return _src;}

      if(_src != nullptr)
      {
        for(; *_src;)
        {
          const char* __pat = _pat;
          for(; *__pat;)
          {
            if(*__pat++ == *_src)
            { return _src;}
          }
          ++_src;
        }
      }
      return nullptr;
    }

  }
}
