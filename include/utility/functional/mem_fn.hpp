
#ifndef __UTILITY_FUNCTIONAL_MEM_FN__
#define __UTILITY_FUNCTIONAL_MEM_FN__

#include<utility/config/utility_config.hpp>

#include<utility/algorithm/forward.hpp>

#include<utility/functional/invoke.hpp>

#include<utility/trait/type/miscellaneous/invoke_result.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(functional)
    template<typename _Fn>
    class __UTILITY_TEMPLATE_VIS mem_fner
    {
      public:
        typedef _Fn function_type;

      private:
        template<typename... _Args>
        using return_t = typename trait::type::miscellaneous::invoke_result<
          _Fn, _Args...
        >::type;

      private:
        type __func;

      public:
        mem_fner(type _func) noexcept: __func{_func}
        { }

      public:
        template<typename... _Args>
        inline return_t<_Args...> operator()(_Args&&... _args)
        {
          using algorithm::forward;
          return invoke(__func, forward<_Args>(_args)...);
        }

    };
    template<typename _Ret, typename _C>
    inline mem_fner<_Ret _C::*> mem_fn(_Ret _C::* _mem_func) noexcept
    { return mem_fner<_Ret _C::*>{_mem_func};}
  __utility_interspace_end(functional)
__utility_globalspace_end(utility)


#endif // ! __UTILITY_FUNCTIONAL_MEM_FN__
