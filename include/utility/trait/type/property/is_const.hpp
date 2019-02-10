
#ifndef __UTILITY_TRAIT_TYPE_PROPERTY_IS_CONST__
#define __UTILITY_TRAIT_TYPE_PROPERTY_IS_CONST__

#include<utility/trait/trait_helper.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
     __utility_interspace_start(type)
    {
       __utility_interspace_start(property)
      {
        // is_const
        template<typename _T>
        struct is_const: public false_type
        { };
        template<typename _T>
        struct is_const<_T const>: public true_type
        { };

      }
    }
  }
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_PROPERTY_IS_CONST__
