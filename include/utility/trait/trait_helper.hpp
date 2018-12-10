
#ifndef __UTILITY_TRAIT_TRAIT_HELPER__
#define __UTILITY_TRAIT_TRAIT_HELPER__

#include<utility/config/utility_config.hpp>
#include<utility/trait/integral_constant.hpp>

// Forward declaration
namespace utility
{
  namespace functional
  {
    template<typename _T>
    class reference_wrapper;
  }
}

namespace utility
{
  namespace trait
  {
    template<typename... Ts>
    struct void_type
    { typedef void type;};

#if defined(__UTILITY_NO_CPP17__)
    template<typename... _Types>
    using void_t = typename void_type<_Types...>::type;
#else
    template<typename ...>
    using void_t = void;
#endif // ! __UTILITY_NO_CPP14__

    /**
    * @brief unsupport tag
    * @author Inochi Amaoto
    * @warning this tag does not inherit from integral_constant,
    *          it's a independent class
    */
    template<bool _Default = false>
    struct unsupport_trait
    {
      constexpr static bool value = _Default;
      typedef bool value_type;
      typedef unsupport_trait type;
      constexpr operator value_type() const noexcept
      { return _Default;}
      constexpr value_type operator()() const noexcept
      { return _Default;}
    };

    namespace __opt__
    {
      template<typename _T, typename _U>
      struct __wrapper__
      { typedef _T type;};
      template<typename _T, typename _U>
      struct __wrapper__<_T, functional::reference_wrapper<_U>>
      { typedef _U& type;};

      template<typename _T>
      struct __is_reference_wrapper__: public trait::false_type
      { };
      template<typename _T>
      struct __is_reference_wrapper__<functional::reference_wrapper<_T>>:
        public trait::false_type
      { };

      template<typename _T>
      struct __transport__
      { typedef _T type;};
    }
  }
}


#endif // ! __UTILITY_TRAIT_TRAIT_HELPER__
