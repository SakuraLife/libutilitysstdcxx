
#ifndef __UTILITY_TRAIT_TYPE_PROPERTY_IS_FINAL__
#define __UTILITY_TRAIT_TYPE_PROPERTY_IS_FINAL__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/config/trait_config.hpp>

#if !defined(__UTILITY_NO_CPP14__) && __utility_has_is_final

# include<utility/trait/config/trait_config.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(property)
        // is_final
        template<typename _T>
        struct is_final: public integral_constant<bool, __utility_is_final(_T)>
        { };

      __utility_interspace_end(property)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#include<utility/trait/config/trait_undef.hpp>

#else // __UTILITY_NO_CPP14__ && __utility_has_is_final

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(property)
        // is_final
        template<typename _T>
        struct is_final : public trait::unsupport_trait<true>
        { };

      __utility_interspace_end(property)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)


#endif // ! __UTILITY_NO_CPP14__ && __utility_has_is_final


#endif // __UTILITY_TRAIT_TYPE_PROPERTY_IS_FINAL__
