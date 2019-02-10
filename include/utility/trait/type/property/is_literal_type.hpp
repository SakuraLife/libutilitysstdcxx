
#ifndef __UTILITY_TRAIT_TYPE_PROPERTY_IS_LITERAL_TYPE__
#define __UTILITY_TRAIT_TYPE_PROPERTY_IS_LITERAL_TYPE__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/type/categories/is_scalar.hpp>
#include<utility/trait/type/categories/is_reference.hpp>
#include<utility/trait/type/transform/remove_all_extents.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
     __utility_interspace_start(type)
    {
       __utility_interspace_start(property)
      {
        // is_literal_type
        template<typename _T>
        struct is_literal_type : public
          integral_constant<bool,
            trait::type::categories::is_scalar<
              trait::type::transform::remove_all_extents_t<_T>
            >::value ||
            trait::type::categories::is_reference<
              trait::type::transform::remove_all_extents_t<_T>
            >::value
          >
        { };
      }
    }
  }
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_PROPERTY_IS_LITERAL_TYPE__
