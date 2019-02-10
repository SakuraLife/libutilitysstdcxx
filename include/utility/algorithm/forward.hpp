
#ifndef __UTILITY_ALGORITHM_FORWARD__
#define __UTILITY_ALGORITHM_FORWARD__

#include<utility/config/utility_config.hpp>
#include<utility/trait/type/transform/remove_reference.hpp>
#include<utility/trait/type/categories/is_lvalue_reference.hpp>
#include<utility/config/utility_config.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(algorithm)
    template<typename _T>
    __UTILITY_CPP14_CONSTEXPR__
    _T&& forward(
      typename trait::type::transform::remove_reference<_T>::type& _val) noexcept
    { return static_cast<_T&&>(_val);}

    template<typename _T>
    __UTILITY_CPP14_CONSTEXPR__
    _T&& forward(
      typename trait::type::transform::remove_reference<_T>::type&& _val) noexcept
    {
      static_assert(
        !trait::type::categories::is_lvalue_reference<_T>::value,
        "Can not transform a lvalue to a rvalue!"
      );
      return static_cast<_T&&>(_val);
    }
  __utility_interspace_end(algorithm)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_ALGORITHM_FORWARD__
