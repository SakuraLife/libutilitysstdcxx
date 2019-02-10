
#ifndef __UTILITY_TRAIT_TYPE_FEATURES_IS_NOTHROW_ASSIGNABLE__
#define __UTILITY_TRAIT_TYPE_FEATURES_IS_NOTHROW_ASSIGNABLE__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/type/type_trait_special.hpp>
#include<utility/trait/type/features/is_assignable.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(features)
        // is_nothrow_assignable
        namespace __impl
        {
          using trait::type::special::declval;

          template<bool, typename _To, typename _From>
          struct __is_nothrow_assignable_helper;

          template<typename _To, typename _From>
          struct __is_nothrow_assignable_helper<false, _To, _From> :
            public false_type
          { };
          template<typename _To, typename _From>
          struct __is_nothrow_assignable_helper<true, _To, _From> :
            public integral_constant<bool,
              noexcept(declval<_To>() = declval<_From>())
            >
          { };
        }
        template<typename _T, typename _U>
        struct is_nothrow_assignable: public
          __impl::__is_nothrow_assignable_helper<
            is_assignable<_T, _U>::value, _T, _U
          >
        { };

      __utility_interspace_end(features)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_FEATURES_IS_NOTHROW_ASSIGNABLE__
