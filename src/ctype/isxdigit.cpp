
#include<utility/sstd/cctype.hpp>

namespace utility
{
  namespace sstd
  {
    int isxdigit(int _ch) noexcept
    { return (cctype(_ch) & __CTYPE_XDIGHT) != 0;}

  }
}
