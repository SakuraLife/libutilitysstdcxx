
#include<utility/sstd/cctype.hpp>

namespace utility
{
  namespace sstd
  {
    int isdigit(int _ch) noexcept
    { return (cctype(_ch) & __CTYPE_DIGIT) != 0;}

  }
}
