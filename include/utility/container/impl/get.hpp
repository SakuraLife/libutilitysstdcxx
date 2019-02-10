
#ifndef __UTILITY_CONTAINER_IMPL_GET__
#define __UTILITY_CONTAINER_IMPL_GET__

#include<utility/config/utility_config.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(container)
  {
    template<size_t _Id, typename _T>
    __UTILITY_CPP14_CONSTEXPR__
    inline _T& get(_T& _val)
    { return _val;}
    template<size_t _Id, typename _T>
    __UTILITY_CPP14_CONSTEXPR__
    inline const _T& get(const _T& _val)
    { return _val;}
    template<size_t _Id, typename _T>
    __UTILITY_CPP14_CONSTEXPR__
    inline _T&& get(_T&& _val)
    { return static_cast<_T&&>(_val);}
    template<size_t _Id, typename _T>
    __UTILITY_CPP14_CONSTEXPR__
    inline const _T&& get(const _T&& _val)
    { return static_cast<const _T&&>(_val);}
  }
__utility_globalspace_end(utility)

#endif // ! __UTILITY_CONTAINER_IMPL_GET__
