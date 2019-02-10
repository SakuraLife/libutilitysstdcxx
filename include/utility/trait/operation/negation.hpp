
#ifndef __UTILITY_TRAIT_OPERATION_NEGATION__
#define __UTILITY_TRAIT_OPERATION_NEGATION__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/opt/__logical__.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(operation)
      // negation
      template<typename _T>
      struct negation: __opt__::__type_not__<_T>
      { };

#if !defined(__UTILITY_NO_CPP14__)
      template<typename _T>
      constexpr bool negation_v = negation<_T>::value;
#endif

    __utility_interspace_end(operation)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_TRAIT_OPERATION_NEGATION__
