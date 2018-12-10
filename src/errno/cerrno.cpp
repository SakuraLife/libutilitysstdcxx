#include<utility/sstd/cerrno.hpp>

namespace utility
{
  namespace sstd
  {
    thread_local static int sstd_errno = 0;
    int* errno_ptr() noexcept
    { return &sstd_errno;}

  }
}
