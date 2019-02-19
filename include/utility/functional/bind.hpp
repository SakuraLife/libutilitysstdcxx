
#ifndef __UTILITY_FUNCTIONAL_BIND__
#define __UTILITY_FUNCTIONAL_BIND__

#include<utility/config/utility_config.hpp>

#include<utility/algorithm/forward.hpp>

#include<utility/container/tuple.hpp>

#include<utility/functional/placeholders.hpp>
#include<utility/functional/reference_wrapper.hpp>
#include<utility/functional/invoke.hpp>

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/integer_sequence.hpp>
#include<utility/trait/type/releations/is_convertible.hpp>
#include<utility/trait/type/transform/decay.hpp>
#include<utility/trait/type/miscellaneous/enable_if.hpp>
#include<utility/trait/type/miscellaneous/invoke_result.hpp>
#include<utility/trait/type/features/is_invocable.hpp>


__utility_globalspace_start(utility)
  __utility_interspace_start(functional)
    template<typename _Expr>
    struct __UTILITY_TEMPLATE_VIS is_bind_expression: public trait::false_type
    { };

    struct bind_auto_detected;

    namespace __detail
    {
      using trait::index_sequence;
      using trait::make_index_sequence;
      using trait::type::releations::is_convertible;
      using trait::type::transform::decay_t;
      using trait::type::miscellaneous::enable_if;
      using trait::type::miscellaneous::enable_if_t;
      using trait::type::miscellaneous::invoke_result_t;
      using container::tuple;
      using container::tuple_element_t;

      template<typename _Binder, typename... _Types, size_t... _Idx>
      inline invoke_result_t<_Binder&, _Types...>
      __exec_binder_expression(
        _Binder& _binder, tuple<_Types...>& _tuple, index_sequence<_Idx...>
      )
      {
        using container::get;
        return _binder(get<_Idx>(_tuple)...);
      }

      template<bool _Id, typename _Binder, typename... _Types>
      struct __bind_expand_protector
      { typedef invoke_result_t<_Binder, _Types...> type;};
      template<typename _Binder, typename... _Types>
      struct __bind_expand_protector<false, _Binder, _Types...>
      { };

      template<int _Idx, typename _Tuple>
      struct __selector_protector
      { typedef tuple_element_t<_Idx - 1, _Tuple> type;};
      template<typename _Tuple>
      struct __selector_protector<0, _Tuple>
      { };

      template<typename _T, typename _Tuple>
      _T& __selector(reference_wrapper<_T>& _ref, _Tuple&)
      { return _ref.get();}

      template<typename _Binder, typename... _Types>
      typename __bind_expand_protector<
        is_bind_expression<_Binder>::value, _Binder&, _Types...
      >::type
      __selector(_Binder& _binder, tuple<_Types...>& _tuple)
      {
        typedef make_index_sequence<sizeof...(_Types)>  __IdSeq;
        return __exec_binder_expression(_binder, _tuple, __IdSeq{});
      }

      template<typename _Holder, typename... _Types>
      typename __selector_protector<
        is_placeholder<_Holder>::value, tuple<_Types...>
      >::type
      __selector(_Holder& _holder, tuple<_Types...>& _tuple)
      {
        using algorithm::forward;
        using container::get;

        constexpr size_t _Idx = is_placeholder<_Holder>::value - 1;
        typedef tuple_element_t<_Idx, tuple<_Types...>> __target;

        return forward<__target>(get<_Idx>(_tuple));
      }

      template<typename _T, typename _Tuple>
      typename enable_if<
        0 == is_placeholder<_T>::value &&
        !is_bind_expression<_T>::value &&
        !is_reference_wrapper<_T>::value,
        _T&
      >::type
      __selector(_T& _arg, _Tuple&)
      { return _arg;}

      template<
        typename _T,
        typename _Tuple,
        bool = 0 < is_placeholder<_T>::value,
        bool = is_bind_expression<_T>::value,
        bool = is_reference_wrapper<_T>::value
      >
      struct __type_seletcor
      { typedef _T& type;};

      template<typename _T, typename... _Types>
      struct __type_seletcor<_T, tuple<_Types...>, true, false, false>
      {
        typedef tuple_element_t<
          is_placeholder<_T>::value - 1, tuple<_Types...>
        >&& type;
      };

      template<typename _T, typename... _Types>
      struct __type_seletcor<_T, tuple<_Types...>, false, true, false>
      { typedef invoke_result_t<_T&, _Types...> type;};

      template<typename _T, typename _Tuple>
      struct __type_seletcor<_T, _Tuple, false, false, true>
      { typedef typename _T::type type;};

      template<typename _Fn, typename _Bind, typename _Tuple>
      struct __executor_ret;

      template<typename _Fn, typename... _BindArg, typename _ArgTuple>
      struct __executor_ret<_Fn, tuple<_BindArg...>, _ArgTuple>
      {
        typedef invoke_result_t<
          _Fn, typename __type_seletcor<_BindArg, _ArgTuple>::type...
        > type;
      };

      template<typename _Fn, typename... _BindArg, typename _ArgTuple>
      struct __executor_ret<_Fn, const tuple<_BindArg...>, _ArgTuple>
      {
        typedef invoke_result_t<
          _Fn, typename __type_seletcor<const _BindArg, _ArgTuple>::type...
        > type;
      };
    }

    template<typename _Ret>
    class __UTILITY_TEMPLATE_VIS binder_executor
    {
      public:
        template<
          typename _Fn,
          typename _BindTuple, typename _ArgTuple
        >
        using return_t = __detail::enable_if_t<
          __detail::is_convertible<
            typename __detail::__executor_ret<
              _Fn&, _BindTuple, _ArgTuple
            >::type, _Ret
          >::value,
          _Ret
        >;

      public:
        template<
          typename _Fn,
          typename _BindTuple, typename _ArgTuple,
          size_t... _Idx
        >
        static inline
        __detail::enable_if_t<
          __detail::is_convertible<
            typename __detail::__executor_ret<
              _Fn&, _BindTuple, _ArgTuple
            >::type, _Ret
          >::value,
          _Ret
        > exec(
          _Fn& _func, _BindTuple& _bargs, _ArgTuple&& _args,
          trait::index_sequence<_Idx...>
        )
        {
          using container::get;
          return static_cast<_Ret>(
            invoke(_func, __detail::__selector(get<_Idx>(_bargs), _args)...)
          );
        }
    };

    template<>
    class __UTILITY_TYPE_VIS binder_executor<bind_auto_detected>
    {
      public:
        template<
          typename _Fn,
          typename _BindTuple, typename _ArgTuple
        >
        using return_t = typename __detail::__executor_ret<
          _Fn&, _BindTuple, _ArgTuple
        >::type;

      public:
        template<
          typename _Fn,
          typename _BindTuple, typename _ArgTuple,
          size_t... _Idx
        >
        static inline
        typename __detail::__executor_ret<
          _Fn&, _BindTuple, _ArgTuple
        >::type exec(
          _Fn& _func, _BindTuple& _bargs, _ArgTuple&& _args,
          trait::index_sequence<_Idx...>
        )
        {
          using container::get;
          return invoke(_func, __detail::__selector(get<_Idx>(_bargs), _args)...);
        }
    };

    template<>
    class __UTILITY_TYPE_VIS binder_executor<void>
    {
      public:
        template<
          typename _Fn,
          typename _BindTuple, typename _ArgTuple
        >
        using return_t = void;

      public:
        template<
          typename _Fn,
          typename _BindTuple, typename _ArgTuple,
          size_t... _Idx
        >
        static inline
        void exec(
          _Fn& _func, _BindTuple& _bargs, _ArgTuple&& _args,
          trait::index_sequence<_Idx...>
        )
        {
          using container::get;
          invoke(_func, __detail::__selector(get<_Idx>(_bargs), _args)...);
        }
    };

    template<typename _Executor, typename _Fn, typename... _Bind>
    class __UTILITY_TEMPLATE_VIS binder;

    template<typename _Policy, typename _Fn, typename... _Bind>
    class __UTILITY_TEMPLATE_VIS binder<binder_executor<_Policy>, _Fn, _Bind...>
    {
      private:
        typedef __detail::decay_t<_Fn>                        function_type;
        typedef __detail::tuple<__detail::decay_t<_Bind>...>  args_type;
        typedef binder_executor<_Policy>                      executor_type;

      public:
        typedef _Policy    deducte_policy;

      private:
        function_type   __func;
        args_type       __args;

      public:
        template<typename _Func, typename... _BindArgs>
        explicit binder(_Func&& _func, _BindArgs&&... _args):
          __func{algorithm::forward<_Func>(_func)},
          __args{algorithm::forward<_BindArgs>(_args)...}
        { }

        template<typename... _Args>
        typename executor_type::template return_t<
          _Fn, args_type, container::tuple<_Args&&...>
        > operator()(_Args&&... _args)
        {
          using algorithm::forward;
          using container::tuple;
          typedef __detail::make_index_sequence<sizeof...(_Bind)> __IdSeq;
          return executor_type::exec(
            __func, __args, tuple<_Args&&...>{forward<_Args>(_args)...},
            __IdSeq{}
          );
        }
        template<typename... _Args>
        typename executor_type::template return_t<
          _Fn, const args_type, container::tuple<_Args&&...>
        > operator()(_Args&&... _args) const
        {
          using algorithm::forward;
          using container::tuple;
          typedef __detail::make_index_sequence<sizeof...(_Bind)> __IdSeq;
          return executor_type::exec(
            __func, __args, tuple<_Args&&...>{forward<_Args>(_args)...},
            __IdSeq{}
          );
        }

      private:
    };

    template<typename _Ret, typename _Fn, typename... _Bind>
    struct __UTILITY_TEMPLATE_VIS is_bind_expression<binder<_Ret, _Fn, _Bind...>>:
      public trait::true_type
    { };

    template<typename _Fn, typename... _Args>
    inline binder<binder_executor<bind_auto_detected>, _Fn, _Args...>
    bind(_Fn&& _func, _Args&&... _bargs)
    {
      using algorithm::forward;
      return binder<binder_executor<bind_auto_detected>, _Fn, _Args...>{
        forward<_Fn>(_func), forward<_Args>(_bargs)...
      };
    }
    template<typename _R, typename _Fn, typename... _Args>
    inline binder<binder_executor<_R>, _Fn, _Args...>
    bind(_Fn&& _func, _Args&&... _bargs)
    {
      using algorithm::forward;
      return binder<binder_executor<_R>, _Fn, _Args...>{
        forward<_Fn>(_func), forward<_Args>(_bargs)...
      };
    }

  __utility_interspace_end(functional)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_FUNCTIONAL_BIND__
