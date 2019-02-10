

#ifndef __UTILITY_TRAIT_OPT___TYPES____
#define __UTILITY_TRAIT_OPT___TYPES____

#include<utility/config/utility_config.hpp>
#include<utility/trait/opt/__result__.hpp>
#include<utility/trait/opt/__control__.hpp>

#include<utility/trait/integer_sequence.hpp>

/**
 * [type tuple library reference]
 * this library is the meta version of tuple,
 *
 *
 * __type_pair__<T, T>
 * __type_tripair__<T, T, T>
 * __type_array__<T, I>
 * __type_tuple__<T...>
 * type container
 *
 */

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    namespace __opt__
    {
      template<typename _Fp, typename _Sp>
      struct __type_pair__
      {
        typedef _Fp first;
        typedef _Sp second;
      };

      template<typename _Fp, typename _Sp, typename _Tp>
      struct __type_tripair__
      {
        typedef _Fp first;
        typedef _Sp second;
        typedef _Tp third;
      };

      template<typename _T, size_t _Id>
      struct __index_type__
      {
        typedef _T type;
        constexpr static size_t id = _Id;
      };

      template<typename _T, size_t _N>
      struct __type_array__
      {
        typedef _T type;
        constexpr static size_t size = _N;
      };

      template<typename... _Type>
      struct __type_tuple__
      { };
    }
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_TRAIT_OPT___TYPES____
