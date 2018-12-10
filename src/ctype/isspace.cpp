
#include<utility/sstd/cctype.hpp>

namespace utility
{
  namespace sstd
  {
    int isspace(int _ch) noexcept
    { return (cctype(_ch) & __CTYPE_SPACE) != 0;}

  }
}
