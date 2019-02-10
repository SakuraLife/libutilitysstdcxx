
#ifndef __UTILITY_TRAIT_TRAIT_HELPER_IS_SUPPORTED_TRAIT__
#define __UTILITY_TRAIT_TRAIT_HELPER_IS_SUPPORTED_TRAIT__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/type/releations/is_base_of.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    template<typename _T>
    struct is_unsupport_trait :
      public trait::integral_constant<bool,
        trait::type::releations::is_base_of<unsupport_trait<false>, _T>::value ||
        trait::type::releations::is_base_of<unsupport_trait<true>, _T>::value>
    { };
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_TRAIT_TRAIT_HELPER_IS_SUPPORTED_TRAIT__
