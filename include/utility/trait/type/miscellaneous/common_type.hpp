
#ifndef __UTILITY_TRAIT_TYPE_MISCELLANEOUS_COMMON_TYPE__
#define __UTILITY_TRAIT_TYPE_MISCELLANEOUS_COMMON_TYPE__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/opt/__empty__.hpp>
#include<utility/trait/type/transform/decay.hpp>
#include<utility/trait/type/type_trait_special.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(miscellaneous)
        // common_type
        namespace __impl
        {
          using trait::__opt__::__empty__;
          using trait::type::special::declval;
          using trait::type::transform::decay;

          template<typename _T, typename _U>
          struct __common_type_two_helper
          {
            private:
              template<typename __T, typename __U>
              static decay<
                decltype(declval<bool>() ? declval<__T>() : declval<__U>())
              > __test(int);
              template<typename, typename>
              static __empty__ __test(...);

            public:
              typedef decltype(__test<_T, _U>(0)) type;
          };

          template<typename _T>
          struct __common_type_unfold_helper
          {
            private:
              template<typename __T>
              static typename __T::type __test(int);
              template<typename>
              static __empty__ __test(...);

            public:
              typedef decltype(__test<_T>(0)) type;
          };

          template<typename... _Args>
          struct __common_type_helper
          { };

          template<typename _T, typename... _Args>
          struct __common_type_wrapper
          { typedef __common_type_helper<_T, _Args...> type;};
          template<typename... _Args>
          struct __common_type_wrapper<__empty__, _Args...>
          { typedef __empty__ type;};

          template<typename _T>
          struct __common_type_helper<_T>
          { typedef typename trait::type::transform::decay<_T>::type type;};

          template<typename _T, typename _U>
          struct __common_type_helper<_T, _U>: public
            __common_type_two_helper<_T, _U>::type
          { };

          template<typename _T, typename _U, typename... _Args>
          struct __common_type_helper<_T, _U, _Args...>: public
            __common_type_wrapper<
              typename __common_type_unfold_helper<
                __common_type_helper<_T, _U>
              >::type, _Args...
            >::type
          { };
        }
        template<typename... _Ts>
        struct __UTILITY_TEMPLATE_VIS common_type : public __impl::__common_type_helper<_Ts...>
        { };

        template<typename... _Ts>
        using common_type_t = typename common_type<_Ts...>::type;
      __utility_interspace_end(miscellaneous)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_MISCELLANEOUS_COMMON_TYPE__
