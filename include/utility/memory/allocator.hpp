
#ifndef __UTILITY_MEMORY_ADV_ALLOCATOR__
#define __UTILITY_MEMORY_ADV_ALLOCATOR__

#include<utility/memory/basic_allocator.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(memory)
    template<typename _T>
    using allocator = basic_allocator<_T>;
  __utility_interspace_end(memory)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_MEMORY_ADV_ALLOCATOR__
