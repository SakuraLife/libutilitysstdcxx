
#ifndef __UTILITY_TRAIT_TYPE_FEATURES_IS_TRIVIALLY_DESTRUCTIBLE__
#define __UTILITY_TRAIT_TYPE_FEATURES_IS_TRIVIALLY_DESTRUCTIBLE__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/config/trait_config.hpp>

#if __utility_has_has_trivial_destructor

#include<utility/trait/config/trait_config.hpp>
#include<utility/trait/type/features/is_destructible.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
     __utility_interspace_start(type)
    {
       __utility_interspace_start(features)
      {
        // is_trivially_destructible
        template<typename _T>
        struct is_trivially_destructible: public integral_constant<bool,
            is_destructible<_T>::value &&
            __utility_has_trivial_destructor(_T)
          >
        { };

      }
    }
  }
__utility_globalspace_end(utility)

#else // __utility_has_has_trivial_destructor

#include<utility/trait/type/categories/is_scalar.hpp>
#include<utility/trait/type/categories/is_reference.hpp>
#include<utility/trait/type/transform/remove_all_extents.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
     __utility_interspace_start(type)
    {
       __utility_interspace_start(features)
      {
        // is_trivially_destructible
        namespace __impl
        {
          template<typename _T>
          struct __is_trivially_destructible_helper: public
            trait::integral_constant<bool,
              trait::type::categories::is_scalar<_T>::value ||
              trait::type::categories::is_reference<_T>::value>
          { };
        }
        template<typename _T>
        struct is_trivially_destructible : public
          __impl::__is_trivially_destructible_helper<
            typename
            trait::type::transform::remove_all_extents<_T>::type>
        { };
        template<typename _T>
        struct is_trivially_destructible<_T[]> :
          public trait::false_type
        { };

      }
    }
  }
__utility_globalspace_end(utility)

#endif // __utility_has_has_trivial_destructor

#include<utility/trait/config/trait_config.hpp>

#endif // __UTILITY_TRAIT_TYPE_FEATURES_IS_TRIVIALLY_DESTRUCTIBLE__
