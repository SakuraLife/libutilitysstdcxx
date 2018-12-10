
#include<utility/sstd/cctype.hpp>

namespace utility
{
  namespace sstd
  {
    int isupper(int _ch) noexcept
    { return (cctype(_ch) & __CTYPE_UPPER) != 0;}

  }
}
