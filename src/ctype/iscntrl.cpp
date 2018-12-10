
#include<utility/sstd/cctype.hpp>

namespace utility
{
  namespace sstd
  {
    int iscntrl(int _ch) noexcept
    { return (cctype(_ch) & __CTYPE_CNTRL) != 0;}

  }
}
