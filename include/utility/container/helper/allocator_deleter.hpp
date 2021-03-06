

#ifndef __UTILITY_CONTAINER_HELPER_ALLOCATOR_DELETER__
#define __UTILITY_CONTAINER_HELPER_ALLOCATOR_DELETER__

#include<utility/config/utility_config.hpp>
#include<utility/memory/allocator_traits.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(container)
    __utility_interspace_start(_helper)
      template<typename _Alloc>
      struct __UTILITY_TEMPLATE_VIS allocator_deleter
      {
        public:
          typedef _Alloc allocator_type;
          typedef memory::allocator_traits<allocator_type>
            allocator_traits_type;
          typedef typename allocator_traits_type::pointer pointer;
          typedef typename allocator_traits_type::const_pointer const_pointer;

        public:
          allocator_type& __allocator;
          size_t          __length;

        public:
          void operator()(pointer _chunk) noexcept
          {
            allocator_traits_type::deallocate(
              __allocator, _chunk, __length
            );
          }
      };
    __utility_interspace_end(_helper)
  __utility_interspace_end(container)
__utility_globalspace_end(utility)


#endif // ! __UTILITY_CONTAINER_HELPER_ALLOCATOR_DELETER__
