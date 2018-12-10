
#include<utility/sstd/cctype.hpp>

namespace utility
{
  namespace sstd
  {
    int ispunct(int _ch) noexcept
    { return (cctype(_ch) & __CTYPE_PUNCT) != 0;}

  }
}
