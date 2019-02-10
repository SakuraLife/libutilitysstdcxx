
#ifndef __UTILITY_TRAIT_TYPE_PROPERTY_IS_CV__
#define __UTILITY_TRAIT_TYPE_PROPERTY_IS_CV__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/type/property/is_const.hpp>
#include<utility/trait/type/property/is_volatile.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(property)
        // is_cv
        template<typename _T>
        struct is_cv: public false_type
        { };
        template<typename _T>
        struct is_cv<_T const volatile>: public true_type
        { };

      __utility_interspace_end(property)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_PROPERTY_IS_CV__
