
#ifndef __UTILITY_TRAIT_TYPE_PROPERTY_IS_VOLATILE__
#define __UTILITY_TRAIT_TYPE_PROPERTY_IS_VOLATILE__

#include<utility/trait/trait_helper.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(property)
        // is_volatile
        template<typename _T>
        struct is_volatile: public false_type
        { };
        template<typename _T>
        struct is_volatile<_T volatile>: public true_type
        { };

      __utility_interspace_end(property)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_PROPERTY_IS_VOLATILE__
