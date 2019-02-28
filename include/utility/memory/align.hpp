
#ifndef __UTILITY_MEMORY_ALIGN__
#define __UTILITY_MEMORY_ALIGN__

#include<utility/config/utility_config.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(memory)
    __UTILITY_FUNC_VIS
    void* align(size_t _alignment, size_t _size, void*& _ptr, size_t& _space);
  __utility_interspace_end(memory)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_MEMORY_ALIGN__
