
#ifndef __UTILITY_TRAIT_TYPE_PROPERTY_IS_TRIVIAL__
#define __UTILITY_TRAIT_TYPE_PROPERTY_IS_TRIVIAL__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/config/trait_config.hpp>

#if __utility_has_is_trivial

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(property)
        // is_trivial
        template<typename _T>
        struct is_trivial: public
          integral_constant<bool, __utility_is_trivial(_T)>
        { };

      __utility_interspace_end(property)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#else // __utility_has_is_trivial

#include<utility/trait/type/property/is_trivially_copyable.hpp>
#include<utility/trait/type/features/is_trivially_default_constructible.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(property)
        // is_trivial
        template<typename _T>
        struct is_trivial: public integral_constant<bool,
            is_trivially_copyable<_T>::value &&
            features::is_trivially_default_constructible<_T>::value
          >
        { };

      __utility_interspace_end(property)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __utility_has_is_trivial

#include<utility/trait/config/trait_undef.hpp>

#endif // __UTILITY_TRAIT_TYPE_PROPERTY_IS_TRIVIAL__
