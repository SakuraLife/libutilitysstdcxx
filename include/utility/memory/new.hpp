
#ifndef __UTILITY_MEMORY_NEW__
#define __UTILITY_MEMORY_NEW__

#include<utility/config/utility_config.hpp>
#include<utility/exception/bad_alloc.hpp>

// __utility_globalspace_start(utility)
//   __utility_interspace_start(memory)
//     struct nothrow_t { };
//     constexpr nothrow_t nothrow;
//   __utility_interspace_end(memory)
// __utility_globalspace_end(utility)

// void* operator new(size_t __size, void* __ptr)
// { return __ptr;}
// void* operator new[](size_t __size, void* __ptr)
// { return __ptr;}

#endif // ! __UTILITY_MEMORY_NEW__
