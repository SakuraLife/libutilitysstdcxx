
#ifndef __UTILITY_TRAIT_TYPE_PROPERTY_IS_TRIVIAL_COPYABLE__
#define __UTILITY_TRAIT_TYPE_PROPERTY_IS_TRIVIAL_COPYABLE__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/config/trait_config.hpp>

#if __utility_has_is_trivially_copyable

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(property)
        // is_trivially_copyable
        template<typename _T>
        struct is_trivially_copyable: public
          integral_constant<bool, __utility_is_trivially_copyable(_T)>
        { };

      __utility_interspace_end(property)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#else // __utility_has_is_trivially_copyable

#include<utility/trait/type/categories/is_scalar.hpp>
#include<utility/trait/type/transform/remove_all_extents.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(property)
        // is_trivially_copyable
        template<typename _T>
        struct is_trivially_copyable: public
          integral_constant<bool,
            categories::is_scalar<
              transform::remove_all_extents_t<_T>
            >::value
          >
        { };

      __utility_interspace_end(property)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __utility_has_is_trivially_copyable

#include<utility/trait/config/trait_undef.hpp>

#endif // __UTILITY_TRAIT_TYPE_PROPERTY_IS_TRIVIAL_COPYABLE__
