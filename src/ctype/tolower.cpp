
#include<utility/sstd/cctype.hpp>

namespace utility
{
  namespace sstd
  {
    int tolower(int _ch) noexcept
    {
      static const char* __alpha = "abcdefghijklmnopqrstuvwxyz";
      if(isupper(_ch))
      { return static_cast<int>(__alpha[_ch-'A']);}
      return _ch;
    }

  }
}
