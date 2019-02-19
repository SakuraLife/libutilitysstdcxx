
#ifndef __UTILITY_TRAIT_TYPE_FEATURES_IS_COPYABLE__
#define __UTILITY_TRAIT_TYPE_FEATURES_IS_COPYABLE__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/type/features/is_copy_constructible.hpp>
#include<utility/trait/type/features/is_copy_assignable.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(features)
        // is_copyable
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS is_copyable: public trait::integral_constant<bool,
            is_copy_constructible<_T>::value &&
            is_copy_assignable<_T>::value
          >
        { };
      __utility_interspace_end(features)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_TRAIT_TYPE_FEATURES_IS_COPYABLE__
