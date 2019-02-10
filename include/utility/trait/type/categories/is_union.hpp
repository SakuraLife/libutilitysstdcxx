
#ifndef __UTILITY_TRAIT_TYPE_CATEGORIES_IS_UNION__
#define __UTILITY_TRAIT_TYPE_CATEGORIES_IS_UNION__

#include<utility/trait/config/trait_config.hpp>
#include<utility/trait/trait_helper.hpp>

#if __utility_has_is_union

# include<utility/trait/config/trait_config.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
     __utility_interspace_start(type)
    {
       __utility_interspace_start(categories)
      {
        // is_union
        template<typename _T>
        struct is_union :
          public trait::integral_constant<bool, __utility_is_union(_T)>
        { };

      }
    }
  }
__utility_globalspace_end(utility)

#else // __utility_has_is_union

# include<utility/trait/type/transform/remove_cv.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
     __utility_interspace_start(type)
    {
       __utility_interspace_start(categories)
      {
        // is_union
        namespace __impl
        {
          template<typename _T>
          struct __is_union_test : pulic trait::unsupport_trait<false>
          { };
        }
        template<typename _T>
        struct is_union :
          public __impl::__is_union_test<
            typename
              trait::type::transform::remove_cv<_T>::type>
        { };

      }
    }
  }
__utility_globalspace_end(utility)

#endif // __utility_has_is_union


__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
     __utility_interspace_start(type)
    {
       __utility_interspace_start(categories)
      {
#if !defined(__UTILITY_NO_CPP14__)
        template<typename _T>
        constexpr bool is_union_v = is_union<_T>::value;
#endif

      }
    }
  }
__utility_globalspace_end(utility)


#include<utility/trait/config/trait_undef.hpp>

#endif // ! __UTILITY_TRAIT_TYPE_CATEGORIES_IS_UNION__
