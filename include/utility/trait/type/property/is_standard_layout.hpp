
#ifndef __UTILITY_TRAIT_TYPE_PROPERTY_IS_STANDARD_LAYOUT__
#define __UTILITY_TRAIT_TYPE_PROPERTY_IS_STANDARD_LAYOUT__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/config/trait_config.hpp>

#if __utility_has_is_standard_layout

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(property)
        // is_standard_layout
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS is_standard_layout: public
          integral_constant<bool, __utility_is_standard_layout(_T)>
        { };

      __utility_interspace_end(property)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#else // __utility_has_is_standard_layout

#include<utility/trait/type/categories/is_scalar.hpp>
#include<utility/trait/type/transform/remove_all_extents.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(property)
        // is_standard_layout
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS is_standard_layout: public
          integral_constant<bool,
            trait::type::categories::is_scalar<
              trait::type::transform::remove_all_extents_t<_T>
            >::value
          >
        { };

      __utility_interspace_end(property)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __utility_has_is_standard_layout

#endif // __UTILITY_TRAIT_TYPE_PROPERTY_IS_STANDARD_LAYOUT__
