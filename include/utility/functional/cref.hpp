
#ifndef __UTILITY_FUNCTIONAL_CREF__
#define __UTILITY_FUNCTIONAL_CREF__

#include<utility/functional/reference_wrapper.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(functional)
    template<typename _T>
    inline reference_wrapper<const _T> cref(const _T& _val) noexcept
    { return reference_wrapper<const _T>{_val}};
    template<typename _T>
    inline reference_wrapper<const _T> cref(
      reference_wrapper<_T> _wrapper
    ) noexcept
    { return reference_wrapper<const _T>{_wrapper.get()}};
    template<typename _T>
    inline void cref(const _T&&) = delete;
  __utility_interspace_end(functional)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_FUNCTIONAL_CREF__
