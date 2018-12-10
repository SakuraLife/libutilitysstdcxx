
#include<utility/sstd/cctype.hpp>

namespace utility
{
  namespace sstd
  {
    int isalnum(int _ch) noexcept
    { return (cctype(_ch) & __CTYPE_ALNUM) != 0;}

  }
}
