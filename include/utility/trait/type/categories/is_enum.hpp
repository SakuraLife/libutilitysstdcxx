
#ifndef __UTILITY_TRAIT_TYPE_CATEGORIES_IS_ENUM__
#define __UTILITY_TRAIT_TYPE_CATEGORIES_IS_ENUM__

#include<utility/trait/config/trait_config.hpp>
#include<utility/trait/trait_helper.hpp>

#if __utility_has_is_enum

# include<utility/trait/config/trait_config.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
     __utility_interspace_start(type)
    {
       __utility_interspace_start(categories)
      {
        // is_enum
        template<typename _T>
        struct is_enum:
          public trait::integral_constant<bool, __utility_is_enum(_T)>
        { };
      }
    }
  }
__utility_globalspace_end(utility)

#else // __utility_has_is_enum

# if __utility_has_is_union

# include<utility/trait/type/categories/is_void.hpp>
# include<utility/trait/type/categories/is_integral.hpp>
# include<utility/trait/type/categories/is_floating_point.hpp>
# include<utility/trait/type/categories/is_array.hpp>
# include<utility/trait/type/categories/is_pointer.hpp>
# include<utility/trait/type/categories/is_reference.hpp>
# include<utility/trait/type/categories/is_member_pointer.hpp>
# include<utility/trait/type/categories/is_union.hpp>
# include<utility/trait/type/categories/is_class.hpp>
# include<utility/trait/type/categories/is_function.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
     __utility_interspace_start(type)
    {
       __utility_interspace_start(categories)
      {
        // is_enum
        template<typename _T>
        struct is_enum:
          public trait::integral_constant<bool,
            !is_void<_T>::value             &&
            !is_integral<_T>::value         &&
            !is_floating_point<_T>::value   &&
            !is_array<_T>::value            &&
            !is_pointer<_T>::value          &&
            !is_reference<_T>::value        &&
            !is_member_pointer<_T>::value   &&
            !is_union<_T>::value            &&
            !is_class<_T>::value            &&
            !is_function<_T>::value>
        { };
      }
    }
  }
__utility_globalspace_end(utility)

# else // __utility_has_is_union

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
     __utility_interspace_start(type)
    {
       __utility_interspace_start(categories)
      {
        // is_enum
        template<typename _T>
        struct is_enum: pulic unsupport_trait<false>
        { };

      }
    }
  }
__utility_globalspace_end(utility)

# endif // __utility_has_is_union

#endif // __utility_has_is_enum

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
     __utility_interspace_start(type)
    {
       __utility_interspace_start(categories)
      {
#if !defined(__UTILITY_NO_CPP14__)
        template<typename _T>
        constexpr bool is_enum_v = is_enum<_T>::value;
#endif

      }
    }
  }
__utility_globalspace_end(utility)

#include<utility/trait/config/trait_undef.hpp>

#endif // __UTILITY_TRAIT_TYPE_CATEGORIES_IS_ENUM__
