
#ifndef __UTILITY_MEMORY_OBSERVER_PTR__
#define __UTILITY_MEMORY_OBSERVER_PTR__

#include<utility/config/utility_config.hpp>

#include<utility/algorithm/algorithm_auxiliary.hpp>
#include<utility/algorithm/swap.hpp>
#include<utility/algorithm/possible_swap.hpp>

#include<utility/trait/type/releations/is_convertible.hpp>
#include<utility/trait/type/transform/add_reference.hpp>
#include<utility/trait/type/miscellaneous/enable_if.hpp>
#include<utility/trait/type/miscellaneous/common_type.hpp>


namespace utility
{
  namespace memory
  {
    namespace __detail
    {
      using trait::type::releations::is_convertible;
      using trait::type::transform::add_lvalue_reference_t;
      using trait::type::miscellaneous::enable_if;
      using trait::type::miscellaneous::common_type_t;
    }

    template<typename _T>
    class observer_ptr
    {
      public:
        typedef _T element_type;

      private:
        element_type* __ptr;

      public:
        constexpr observer_ptr() noexcept: __ptr{}
        { }
        constexpr observer_ptr(nullptr_t) noexcept: __ptr{}
        { }
        __UTILITY_CPP14_CONSTEXPR__
        explicit observer_ptr(element_type* _ptr) noexcept: __ptr{_ptr}
        { }
        template<
          typename _U,
          typename __detail::enable_if<
            __detail::is_convertible<_U*, element_type*>::value,
          bool>::type = true
        >
        __UTILITY_CPP14_CONSTEXPR__
        observer_ptr(observer_ptr<_U> _other) noexcept:
          __ptr{static_cast<element_type*>(_other.get())}
        { }

      public:
        __UTILITY_CPP14_CONSTEXPR__
        explicit operator bool() const noexcept
        { return __ptr;}
        __UTILITY_CPP14_CONSTEXPR__
        bool empty() const noexcept
        { return __ptr;}


      public:
        __UTILITY_CPP14_CONSTEXPR__
        __detail::add_lvalue_reference_t<element_type>
        operator*() const noexcept
        { return *__ptr;}
        __UTILITY_CPP14_CONSTEXPR__
        element_type operator->() const noexcept
        { return __ptr;}
        __UTILITY_CPP14_CONSTEXPR__
        element_type* get() const noexcept
        { return __ptr;}

      public:
        operator element_type*() const noexcept
        { return __ptr;}

      public:
        __UTILITY_CPP14_CONSTEXPR__
        element_type* release() noexcept
        {
          element_type* __tmp = __ptr;
          __ptr = nullptr;
          return __tmp;
        }
        __UTILITY_CPP14_CONSTEXPR__
        void reset(element_type* _ptr = nullptr) noexcept
        { __ptr = _ptr;}


      public:
        __UTILITY_CPP14_CONSTEXPR__
        void swap(observer_ptr& _other) noexcept
        {
          using algorithm::swap;
          swap(__ptr, _other.__ptr);
        }
        __UTILITY_CPP14_CONSTEXPR__
        void possible_swap(observer_ptr& _other) noexcept
        {
          using algorithm::swap;
          swap(__ptr, _other.__ptr);
        }
    };

    template<typename _T, typename _U>
    bool operator==(
      const observer_ptr<_T>& _x, const observer_ptr<_U>& _y
    ) noexcept
    {
      using algorithm::equal_to;
      typedef __detail::common_type_t<_T*, _U*> __common;
      return equal_to<__common>()(_x.get(), _y.get());
    }
    template<typename _T, typename _U>
    bool operator!=(
      const observer_ptr<_T>& _x, const observer_ptr<_U>& _y
    ) noexcept
    { return !(_x == _y);}
    template<typename _T, typename _U>
    bool operator<(
      const observer_ptr<_T>& _x, const observer_ptr<_U>& _y
    ) noexcept
    {
      using algorithm::less;
      typedef __detail::common_type_t<_T*, _U*> __common;
      return less<__common>()(_x.get(), _y.get());
    }
    template<typename _T, typename _U>
    bool operator>(
      const observer_ptr<_T>& _x, const observer_ptr<_U>& _y
    ) noexcept
    { return _y < _x;}
    template<typename _T, typename _U>
    bool operator<=(
      const observer_ptr<_T>& _x, const observer_ptr<_U>& _y
    ) noexcept
    { return !(_y < _x);}
    template<typename _T, typename _U>
    bool operator>=(
      const observer_ptr<_T>& _x, const observer_ptr<_U>& _y
    ) noexcept
    { return !(_x < _y);}
    template<typename _T>
    bool operator==(const observer_ptr<_T>& _x, nullptr_t) noexcept
    { return _x.empty();}
    template<typename _U>
    bool operator==(nullptr_t, const observer_ptr<_U>& _y) noexcept
    { return _y.empty();}
    template<typename _T>
    bool operator!=(const observer_ptr<_T>& _x, nullptr_t) noexcept
    { return !_x;}
    template<typename _U>
    bool operator!=(nullptr_t, const observer_ptr<_U>& _y) noexcept
    { return !_y;}


    template<typename _T>
    observer_ptr<_T> make_observer(_T* _ptr) noexcept
    { return observer_ptr<_T>{_ptr};}
  }
}

#endif // ! __UTILITY_MEMORY_OBSERVER_PTR__
