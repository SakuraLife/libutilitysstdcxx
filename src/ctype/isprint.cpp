
#include<utility/sstd/cctype.hpp>

namespace utility
{
  namespace sstd
  {
    int isprint(int _ch) noexcept
    { return (cctype(_ch) & __CTYPE_PRINT) != 0;}

  }
}
