
#include<utility/sstd/cctype.hpp>

namespace utility
{
  namespace sstd
  {
    int islower(int _ch) noexcept
    { return (cctype(_ch) & __CTYPE_LOWER) != 0;}

  }
}
