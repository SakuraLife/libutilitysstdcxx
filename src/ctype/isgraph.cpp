
#include<utility/sstd/cctype.hpp>

namespace utility
{
  namespace sstd
  {
    int isgraph(int _ch) noexcept
    { return (cctype(_ch) & __CTYPE_GRAPH) != 0;}

  }
}
