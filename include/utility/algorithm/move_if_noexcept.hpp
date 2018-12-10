
#ifndef __UTILITY_ALGORITHM_MOVE_IF_NOEXCEPT__
#define __UTILITY_ALGORITHM_MOVE_IF_NOEXCEPT__

#include<utility/config/utility_config.hpp>

#include<utility/trait/type/miscellaneous/conditional.hpp>
#include<utility/trait/type/features/is_nothrow_move_constructible.hpp>
#include<utility/trait/type/features/is_nothrow_copy_constructible.hpp>
#include<utility/trait/type/transform/remove_reference.hpp>

namespace utility
{
  namespace algorithm
  {
    /**
     * \brief Move a value if noexcept
     *
     * move_if_noexcept obtains an rvalue reference to its argument
     * if its move constructor does not throw exceptions
     * otherwise obtains an lvalue reference to its argument
     *
     * \param _val the object to be moved or copied
     * \return \b move(_val) or \a _val depend the exception guarantees.
     */
    template<typename _T>
    typename trait::type::miscellaneous::conditional<
      !trait::type::features::is_nothrow_move_constructible<_T>::value &&
      trait::type::features::is_nothrow_copy_constructible<_T>::value,
      const _T&,
      _T&&
    >::type
    move_if_noexcept(_T& _val) noexcept
    {
      typedef trait::type::transform::remove_reference_t<_T> _U;
      return static_cast<_U&&>(_val)
    }
  }
}

#endif // ! __UTILITY_ALGORITHM_MOVE_IF_NOEXCEPT__
