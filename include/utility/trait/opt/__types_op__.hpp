

#ifndef __UTILITY_TRAIT_OPT___TYPES_OP____
#define __UTILITY_TRAIT_OPT___TYPES_OP____

#include<utility/config/utility_config.hpp>
#include<utility/trait/opt/__result__.hpp>
#include<utility/trait/opt/__control__.hpp>
#include<utility/trait/opt/__types__.hpp>

#include<utility/trait/integer_sequence.hpp>

/**
 * [type tuple library reference]
 * this library is the meta version of tuple,
 *
 *
 * __index_type__<T, I>
 * type container with id
 *
 * __make_type_index_sequence__<T...>
 * transfer tuple to <I, T> tuple
 *
 * __type_tuple_size__<T>
 * tuple size
 *
 * __type_tuple_get__<I, T>
 * extract types by id from tuple
 *
 * __type_tuple_get_unique_id__<T, T>
 * extract id by types from tuple, type is unique
 *
 * __type_tuple_get_array__<IS, T>
 * extract types by id array from tuple as tuple
 *
 * __type_tuple_check__<T, T>
 * check type in tuple
 *
 * __checkout_type_feature__<T>
 * repack with tuple
 *
 * __type_tuple_cat__<T...>
 * merge T as one tuple
 *
 *
 */

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    namespace __opt__
    {
      namespace __helper__
      {
        template<typename _IdSeq, typename _T>
        struct __tuple_index_helper__;

        template<size_t... _Id, typename... _Type>
        struct __tuple_index_helper__<
          index_sequence<_Id...>, __type_tuple__<_Type...>
        >
        { typedef __type_tuple__<__index_type__<_Type, _Id>...> type;};
      }

      template<typename... _Type>
      using __make_type_index_sequence__ =
        typename __helper__::__tuple_index_helper__<
          make_index_sequence<sizeof...(_Type)>, __type_tuple__<_Type...>
        >::type;

      template<typename _T>
      struct __type_tuple_size__
      { constexpr static size_t value = 1;};
      template<typename _Fp, typename _Sp>
      struct __type_tuple_size__<__type_pair__<_Fp, _Sp>>
      { constexpr static size_t value = 2;};
      template<typename _Fp, typename _Sp, typename _Tp>
      struct __type_tuple_size__<__type_tripair__<_Fp, _Sp, _Tp>>
      { constexpr static size_t value = 3;};
      template<typename... _Types>
      struct __type_tuple_size__<__type_tuple__<_Types...>>
      { constexpr static size_t value = sizeof...(_Types);};

      namespace __helper__
      {
        template<size_t _Idx, typename _T>
        struct __tuple_get_helper__;

        template<size_t _Idx, size_t... _Id, typename... _Type>
        struct __tuple_get_helper__<
          _Idx,
          __type_tuple__<__index_type__<_Type, _Id>...>
        >
        {
          private:
            struct __private: public __index_type__<_Type, _Id>...
            { };
            template<size_t _Ix, typename _T>
            static __index_type__<_T, _Ix> __test(const __index_type__<_T, _Ix>&);

          public:
            typedef decltype(__test<_Idx>(__private{})) __index_type;
            typedef typename __index_type::type type;
        };

      }

      template<size_t _Idx, typename _T>
      struct __type_tuple_get__;

      template<size_t _Idx, typename... _Type>
      struct __type_tuple_get__<_Idx, __type_tuple__<_Type...>>
      {
        private:
          static_assert(_Idx < sizeof...(_Type), "index out of range.");

        public:
          typedef typename __helper__::__tuple_get_helper__<
            _Idx,
            __make_type_index_sequence__<_Type...>
          >::type type;
      };

      template<size_t _Idx, typename _T, size_t _N>
      struct __type_tuple_get__<_Idx, __type_array__<_T, _N>>
      {
        private:
          static_assert(_Idx < _N, "index out of range.");

        public:
          typedef _T type;
      };

      template<size_t _Idx, typename _Fp, typename _Sp>
      struct __type_tuple_get__<_Idx, __type_pair__<_Fp, _Sp>>:
        public __type_tuple_get__<_Idx, __type_tuple__<_Fp, _Sp>>
      { };

      template<size_t _Idx, typename _Fp, typename _Sp, typename _Tp>
      struct __type_tuple_get__<_Idx, __type_tripair__<_Fp, _Sp, _Tp>>:
        public __type_tuple_get__<_Idx, __type_tuple__<_Fp, _Sp, _Tp>>
      { };

      template<typename _IdSeq, typename _T>
      struct __type_tuple_get_array__;
      template<size_t... _Id, typename... _Type>
      struct __type_tuple_get_array__<
        index_sequence<_Id...>, __type_tuple__<_Type...>
      >
      {
        typedef __type_tuple__<_Type...> tuple_type;
        typedef __type_tuple__<
          typename __type_tuple_get__<_Id, tuple_type>::type...
        > type;
      };
      template<size_t... _Id, typename _T, size_t _N>
      struct __type_tuple_get_array__<
        index_sequence<_Id...>, __type_array__<_T, _N>
      >
      {
        typedef __type_array__<_T, _N> tuple_type;
        typedef __type_tuple__<
          typename __type_tuple_get__<_Id, tuple_type>::type...
        > type;
      };

      template<typename _IdSeq, typename _T>
      using __type_tuple_get_array_type__ =
        typename __type_tuple_get_array__<_IdSeq, _T>::type;

      template<typename _T>
      struct __checkout_type_feature__
      { typedef __type_tuple__<_T> type;};
      template<typename _Fp, typename _Sp>
      struct __checkout_type_feature__<__type_pair__<_Fp, _Sp>>
      { typedef __type_pair__<_Fp, _Sp> type;};
      template<typename _Fp, typename _Sp, typename _Tp>
      struct __checkout_type_feature__<__type_tripair__<_Fp, _Sp, _Tp>>
      { typedef __type_tripair__<_Fp, _Sp, _Tp> type;};
      template<typename _T, size_t _N>
      struct __checkout_type_feature__<__type_array__<_T, _N>>
      {
        typedef typename __type_tuple_get_array__<
          make_index_sequence<_N>, __type_array__<_T, _N>
        >::type type;
      };
      template<typename... _Types>
      struct __checkout_type_feature__<__type_tuple__<_Types...>>
      { typedef __type_tuple__<_Types...> type;};

      template<typename... _Types>
      struct __type_tuple_cat__;

      template<>
      struct __type_tuple_cat__<>
      { typedef __type_tuple__<> type;};
      // template<typename _Fp, typename _Sp>
      // struct __type_tuple_cat__<__type_pair__<_Fp, _Sp>>
      // { typedef __type_tuple__<_Fp, _Sp> type;};
      // template<typename _Fp, typename _Sp, typename _Tp>
      // struct __type_tuple_cat__<__type_tripair__<_Fp, _Sp, _Tp>>
      // { typedef __type_tuple__<_Fp, _Sp, _Tp> type;};
      template<typename... _Types>
      struct __type_tuple_cat__<__type_tuple__<_Types...>>
      { typedef __type_tuple__<_Types...> type;};

      template<typename _T, typename... _ArgTypes>
      struct __type_tuple_cat__<_T, _ArgTypes...>:
        public __type_tuple_cat__<__type_tuple__<_T>, _ArgTypes...>
      { };
      template<typename _Fp, typename _Sp, typename... _ArgTypes>
      struct __type_tuple_cat__<__type_pair__<_Fp, _Sp>, _ArgTypes...>:
        public __type_tuple_cat__<__type_tuple__<_Fp, _Sp>, _ArgTypes...>
      { };
      template<typename _Fp, typename _Sp, typename _Tp, typename... _ArgTypes>
      struct __type_tuple_cat__<__type_tripair__<_Fp, _Sp, _Tp>, _ArgTypes...>:
        public __type_tuple_cat__<__type_tuple__<_Fp, _Sp, _Tp>, _ArgTypes...>
      { };
      template<typename... _Types, typename _T, typename... _ArgTypes>
      struct __type_tuple_cat__<__type_tuple__<_Types...>, _T, _ArgTypes...>:
        public __type_tuple_cat__<__type_tuple__<_Types..., _T>, _ArgTypes...>
      { };
      template<
        typename... _Types, typename _Fp, typename _Sp,
        typename... _ArgTypes
      >
      struct __type_tuple_cat__<
        __type_tuple__<_Types...>,
        __type_pair__<_Fp, _Sp>,
        _ArgTypes...
      >:public __type_tuple_cat__<
          __type_tuple__<_Types..., _Fp, _Sp>, _ArgTypes...
        >
      { };
      template<
        typename... _Types, typename _Fp, typename _Sp, typename _Tp,
        typename... _ArgTypes
      >
      struct __type_tuple_cat__<
        __type_tuple__<_Types...>,
        __type_tripair__<_Fp, _Sp, _Tp>,
        _ArgTypes...
      >:public __type_tuple_cat__<
          __type_tuple__<_Types..., _Fp, _Sp, _Tp>, _ArgTypes...
        >
      { };
      template<typename... _Types, typename... _Utypes, typename... _ArgTypes>
      struct __type_tuple_cat__<
        __type_tuple__<_Types...>,
        __type_tuple__<_Utypes...>,
        _ArgTypes...
      >:public __type_tuple_cat__<
        __type_tuple__<_Types..., _Utypes...>, _ArgTypes...
      >
      { };

      constexpr static size_t __type_not_find_or_duplicate__ = -1;
      namespace __helper__
      {

        template<typename _T, typename _Tuple>
        struct __tuple_get_unique_id_helper__;

        template<typename _T, size_t... _Id, typename... _Type>
        struct __tuple_get_unique_id_helper__<
          _T, __type_tuple__<__index_type__<_Type, _Id>...>
        >
        {
          private:
            struct __private: public __index_type__<_Type, _Id>...
            { };
            struct __not_find
            { constexpr static size_t id = __type_not_find_or_duplicate__;};
            template<typename _Tp, size_t _Ix>
            static __index_type__<_Tp, _Ix>
              __test(const __index_type__<_Tp, _Ix>&);
            template<typename _Tp>
            static __not_find __test(...);

          public:
            typedef decltype(__test<_T>(__private{})) type;
            constexpr static size_t id = type::id;
        };
      }

      template<typename _T, typename _Tuple>
      struct __type_tuple_get_unique_id__;

      template<typename _T, typename... _Type>
      struct __type_tuple_get_unique_id__<_T, __type_tuple__<_Type...>>
      {
        public:
          constexpr static size_t id =
            __helper__::__tuple_get_unique_id_helper__<
              _T, __make_type_index_sequence__<_Type...>
            >::id;
      };

      template<typename _T, typename _Tuple>
      struct __type_tuple_check__;
      template<typename _T, typename... _Type>
      struct __type_tuple_check__<_T, __type_tuple__<_Type...>>
      {
        private:
          template<typename _Tp>
          static auto __test(int) -> decltype(
            __type_array__<__false__, sizeof...(_Type)>{
              {__eq__<_Tp, _Type>{}...}
            }
          );
          template<typename _Tp>
          static char __test(...);

        public:
          constexpr static bool value =
            __eq__<decltype(__test<_T>(0)), char>::value;
      };

      // template<typename... _Types>
      // struct __type_tuple_unique__
      // {
      //   ;
      // };
      // template<>
      // struct __type_tuple_unique__<>
      // { typedef __type_tuple__<> type;};
    }
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_TRAIT_OPT___TYPES_OP____
