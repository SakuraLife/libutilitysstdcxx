
#ifndef __UTILITY_TRAIT_OPERATION_DISJUNCTION__
#define __UTILITY_TRAIT_OPERATION_DISJUNCTION__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/opt/__logical__.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(operation)
      // disjunction
      template<typename... _Types>
      struct disjunction: __opt__::__type_or__<_Types...>
      { };

#if !defined(__UTILITY_NO_CPP14__)
      template<typename... _Types>
      constexpr bool disjunction_v = disjunction<_Types...>::value;
#endif

    __utility_interspace_end(operation)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_TRAIT_OPERATION_DISJUNCTION__
