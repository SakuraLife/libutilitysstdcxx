
#include<utility/sstd/cctype.hpp>

namespace utility
{
  namespace sstd
  {
    int toupper(int _ch) noexcept
    {
      static const char* __alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
      if(islower(_ch))
      { return static_cast<int>(__alpha[_ch-'a']);}
      return _ch;
    }

  }
}
