
#ifndef __UTILITY_MEMORY_RAW_DELETE__
#define __UTILITY_MEMORY_RAW_DELETE__

#include<utility/config/utility_config.hpp>

#include<utility/memory/basic_deallocator.hpp>

namespace utility
{
  namespace memory
  {
    struct raw_delete
    {
      template<typename _T>
      inline void operator()(_T* _ptr)
      { default_deallocate(_ptr);}
    };
  }
}

#endif // ! __UTILITY_MEMORY_RAW_DELETE__
