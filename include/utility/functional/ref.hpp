
#ifndef __UTILITY_FUNCTIONAL_REF__
#define __UTILITY_FUNCTIONAL_REF__

#include<utility/functional/reference_wrapper.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(functional)
  {
    template<typename _T>
    inline reference_wrapper<_T> ref(_T& _val) noexcept
    { return reference_wrapper<_T>{_val}};
    template<typename _T>
    inline reference_wrapper<_T> ref(reference_wrapper<_T> _wrapper) noexcept
    { return reference_wrapper<_T>{_wrapper.get()}};
    template<typename _T>
    inline void ref(const _T&&) = delete;
  }
__utility_globalspace_end(utility)

#endif // ! __UTILITY_FUNCTIONAL_REF__
