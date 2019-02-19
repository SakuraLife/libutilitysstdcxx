
#ifndef __UTILITY_TRAIT_TYPE_MISCELLANEOUS_ALIGNED_STORAGE__
#define __UTILITY_TRAIT_TYPE_MISCELLANEOUS_ALIGNED_STORAGE__

#include<utility/trait/trait_helper.hpp>
#include<utility/config/utility_config.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(miscellaneous)
        // aligned_storage
        namespace __impl
        {
          template<size_t _Len>
          struct __aligned_storage_helper
          {
            union type
            {
              unsigned char __data[_Len];
              struct alignas(0) { } __align;
            };
          };
        }
        template<
          size_t _Len,
          size_t _Align = __utility_alignof(
            typename __impl::__aligned_storage_helper<_Len>::type
          )
        >
        struct __UTILITY_TEMPLATE_VIS aligned_storage
        {
          union type
          {
            unsigned char __data[_Len];
            struct alignas(_Align) { } __align;
          };
        };

        template<
          size_t _Len,
          size_t _Align = __utility_alignof(
            typename __impl::__aligned_storage_helper<_Len>::type
          )
        >
        using aligned_storage_t = typename aligned_storage<_Len, _Align>::type;
      __utility_interspace_end(miscellaneous)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_MISCELLANEOUS_ALIGNED_STORAGE__
