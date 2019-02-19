
#ifndef __UTILITY_MEMORY_ALLOCATOR_HELPER__
#define __UTILITY_MEMORY_ALLOCATOR_HELPER__

#include<utility/config/utility_config.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(memory)
    struct __UTILITY_TYPE_VIS allocator_arg_t
    { explicit allocator_arg_t() = default;};

    __UTILITY_CPP17_INLINE__
    constexpr memory::allocator_arg_t allocator_arg{};
  __utility_interspace_end(memory)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_MEMORY_ALLOCATOR_HELPER__
