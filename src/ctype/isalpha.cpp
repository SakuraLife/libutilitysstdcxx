
#include<utility/sstd/cctype.hpp>

namespace utility
{
  namespace sstd
  {
    int isalpha(int _ch) noexcept
    { return (cctype(_ch) & __CTYPE_ALPHA) != 0;}

  }
}
