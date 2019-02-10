
#ifndef __UTILITY_TRAIT_OPERATION_CONJUNCTION__
#define __UTILITY_TRAIT_OPERATION_CONJUNCTION__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/opt/__logical__.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
     __utility_interspace_start(operation)
    {
      // conjunction
      template<typename... _Types>
      struct conjunction: __opt__::__type_and__<_Types...>
      { };

#if !defined(__UTILITY_NO_CPP14__)
      template<typename... _Types>
      constexpr bool conjunction_v = conjunction<_Types...>::value;
#endif

    }
  }
__utility_globalspace_end(utility)

#endif // ! __UTILITY_TRAIT_OPERATION_CONJUNCTION__
