
#ifndef __UTILITY_TRAIT_TRAIT_HELPER__
#define __UTILITY_TRAIT_TRAIT_HELPER__

#include<utility/config/utility_config.hpp>
#include<utility/trait/integral_constant.hpp>

// Forward declaration
__utility_globalspace_start(utility)
  __utility_interspace_start(functional)
    template<typename _T>
    class __UTILITY_TYPE_VIS reference_wrapper;
  __utility_interspace_end(functional)
__utility_globalspace_end(utility)

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    template<typename... Ts>
    struct __UTILITY_TYPE_VIS _void_type
    { typedef void type;};

#if defined(__UTILITY_NO_CPP17__)
    template<typename... _Types>
    using void_t = typename _void_type<_Types...>::type;
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
    struct __UTILITY_TYPE_VIS unsupport_trait
    {
      constexpr static bool value = _Default;
      typedef bool value_type;
      typedef unsupport_trait type;
      constexpr operator value_type() const noexcept
      { return _Default;}
      constexpr value_type operator()() const noexcept
      { return _Default;}
    };

    enum class _trait_state: unsigned char
    {
      unsupport = 0,
      support = 1,
      trivial = 3
    };

    UTILITY_ALWAYS_INLINE constexpr inline
    _trait_state operator&(_trait_state _x, _trait_state _y) noexcept
    {
      return static_cast<_trait_state>(
        static_cast<unsigned char>(_x) & static_cast<unsigned char>(_y)
      );
    }

    constexpr bool _is_support_trait_state(_trait_state _state)
    { return (_state & _trait_state::support) == _trait_state::support;}

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
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)


#endif // ! __UTILITY_TRAIT_TRAIT_HELPER__
