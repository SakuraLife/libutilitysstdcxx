
#include<utility/sstd/cctype.hpp>

namespace utility
{
  namespace sstd
  {
    int isblank(int _ch) noexcept
    { return (cctype(_ch) & __CTYPE_BLANK) != 0;}

  }
}
