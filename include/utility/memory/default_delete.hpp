
#ifndef __UTILITY_MEMORY_DEFAULT_DELETE__
#define __UTILITY_MEMORY_DEFAULT_DELETE__

#include<utility/config/utility_config.hpp>
#include<utility/trait/type/categories/is_void.hpp>
#include<utility/trait/type/releations/is_convertible.hpp>
#include<utility/trait/type/miscellaneous/enable_if.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(memory)
    template<typename _T>
    struct __UTILITY_TEMPLATE_VIS default_delete
    {
      constexpr default_delete() noexcept = default;
      template<
        typename _U,
        typename
        trait::type::miscellaneous::enable_if<
          trait::type::releations::is_convertible<_U*,
          _T*>::value,
          bool
        >::type = true
      >
      inline default_delete(const default_delete<_U>&) noexcept
      { }

      template<typename _U>
      inline typename
      trait::type::miscellaneous::enable_if<
        trait::type::releations::is_convertible<_U*, _T*>::value,
        void
      >::type
      operator()(_U* __ptr) const
      {
        static_assert(
          sizeof(_T) > 0 ||
          !trait::type::categories::is_void<_T>::value,
          "default_delete need a complete type"
        );
        delete __ptr;
      }

    };
    template<typename _T>
    struct __UTILITY_TEMPLATE_VIS default_delete<_T[]>
    {
      constexpr default_delete() noexcept = default;
      template<
        typename _U,
        typename
        trait::type::miscellaneous::enable_if<
          trait::type::releations::is_convertible<_U(*)[],
          _T(*)[]>::value,
          bool
        >::type = true
      >
      inline default_delete(const default_delete<_U[]>&) noexcept
      { }

      template<typename _U>
      inline typename
      trait::type::miscellaneous::enable_if<
          trait::type::releations::is_convertible<_U(*)[], _T(*)[]
        >::value,
        void
      >::type
      operator()(_U* __ptr) const
      {
        static_assert(
          sizeof(_T) > 0 ||
          !trait::type::categories::is_void<_T>::value,
          "default_delete need a complete type"
        );
        delete[] __ptr;
      }

    };

  __utility_interspace_end(memory)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_MEMORY_DEFAULT_DELETE__
