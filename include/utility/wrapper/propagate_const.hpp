
#ifndef __UTILITY_WRAPPER_PROPAGATE_CONST__
#define __UTILITY_WRAPPER_PROPAGATE_CONST__

#include<utility/config/utility_config.hpp>

#include<utility/algorithm/algorithm_auxiliary.hpp>
#include<utility/algorithm/forward.hpp>
#include<utility/algorithm/move.hpp>
#include<utility/algorithm/swap.hpp>
#include<utility/algorithm/possible_swap.hpp>

#include<utility/trait/type/type_trait_special.hpp>
#include<utility/trait/type/categories/is_array.hpp>
#include<utility/trait/type/categories/is_function.hpp>
#include<utility/trait/type/categories/is_pointer.hpp>
#include<utility/trait/type/categories/is_reference.hpp>
#include<utility/trait/type/categories/is_void.hpp>
#include<utility/trait/type/releations/is_same.hpp>
#include<utility/trait/type/releations/is_convertible.hpp>
#include<utility/trait/type/transform/remove_reference.hpp>
#include<utility/trait/type/transform/remove_pointer.hpp>
#include<utility/trait/type/transform/remove_cv.hpp>
#include<utility/trait/type/features/is_constructible.hpp>
#include<utility/trait/type/features/is_assignable.hpp>
#include<utility/trait/type/features/is_swappable.hpp>
#include<utility/trait/type/features/is_possible_swappable.hpp>
#include<utility/trait/type/miscellaneous/enable_if.hpp>


__utility_globalspace_start(utility)
  __utility_interspace_start(wrapper)
    namespace __detail
    {
      using trait::type::special::declval;
      using trait::type::categories::is_array;
      using trait::type::categories::is_function;
      using trait::type::categories::is_pointer;
      using trait::type::categories::is_reference;
      using trait::type::categories::is_void;
      using trait::type::features::is_assignable;
      using trait::type::features::is_constructible;
      using trait::type::features::is_swappable;
      using trait::type::features::is_nothrow_swappable;
      using trait::type::features::is_possible_swappable;
      using trait::type::features::is_nothrow_possible_swappable;
      using trait::type::releations::is_same;
      using trait::type::releations::is_convertible;
      using trait::type::transform::remove_reference_t;
      using trait::type::transform::remove_pointer_t;
      using trait::type::transform::remove_cv_t;
      using trait::type::miscellaneous::enable_if;

      template<typename _T, typename _U>
      __UTILITY_CPP14_CONSTEXPR__
      inline _T* __get(_U& _val)
      { return _val.get();}
      template<typename _T, typename _U>
      __UTILITY_CPP14_CONSTEXPR__
      inline _T* __get(_U* _ptr) noexcept
      { return _ptr;}
      template<typename _T, typename _U>
      __UTILITY_CPP14_CONSTEXPR__
      inline const _T* __get(const _U& _val)
      { return _val.get();}
      template<typename _T, typename _U>
      __UTILITY_CPP14_CONSTEXPR__
      inline const _T* __get(const _U* _ptr) noexcept
      { return _ptr;}

      template<typename _U>
      __UTILITY_CPP14_CONSTEXPR__
      inline bool __has(const _U& _val)
      { return static_cast<bool>(_val);}
      template<typename _U>
      __UTILITY_CPP14_CONSTEXPR__
      inline bool __has(const _U* _ptr) noexcept
      { return _ptr;}
    }
    template<typename _T>
    class propagate_const;

    template<typename _T>
    struct is_propagate_const: trait::false_type
    { };
    template<typename _T>
    struct is_propagate_const<propagate_const<_T>>: trait::true_type
    { };

    template<typename _T>
    class propagate_const
    {
      private:
        template<typename>
        friend class propagate_const;

      public:
        typedef __detail::remove_reference_t<
          decltype(*__detail::declval<_T&>())
        > element_type;

      private:
        static_assert(
          !__detail::is_array<_T>::value,
          "propagate_const<_T[]> is ill-formed"
        );
        static_assert(
          !__detail::is_reference<_T>::value,
          "propagate_const<_T&> is ill-formed"
        );
        static_assert(
          !(__detail::is_pointer<_T>::value &&
            __detail::is_function<__detail::remove_pointer_t<_T>>::value),
          "propagate_const with function pointer is ill-formed"
        );
        static_assert(
          !(__detail::is_pointer<_T>::value &&
            __detail::is_void<
              __detail::remove_cv_t<__detail::remove_pointer_t<_T>>
            >::value),
          "propagate_const with void (or cv pointer) is ill-formed"
        );

      private:
        typedef _T __type;

      private:
        __type  __val;

      public:
        constexpr propagate_const() = default;
        constexpr propagate_const(propagate_const&&) = default;

        template<
          typename _U,
          typename __detail::enable_if<
            __detail::is_constructible<_T, _U&&>::value,
          bool>::type = true,
          typename __detail::enable_if<
            __detail::is_convertible<_U&&, _T>::value,
          bool>::type = true
        >
        __UTILITY_CPP14_CONSTEXPR__
        propagate_const(propagate_const<_U>&& _other):
          __val(algorithm::move(_other.__val))
        { }
        template<
          typename _U,
          typename __detail::enable_if<
            __detail::is_constructible<_T, _U&&>::value,
          bool>::type = true,
          typename __detail::enable_if<
            !__detail::is_convertible<_U&&, _T>::value,
          bool>::type = false
        >
        __UTILITY_CPP14_CONSTEXPR__
        explicit propagate_const(propagate_const<_U>&& _other):
          __val(algorithm::move(_other.__val))
        { }

        template<
          typename _U,
          typename __detail::enable_if<
            !is_propagate_const<_U>::value &&
            __detail::is_constructible<_T, _U&&>::value,
          bool>::type = true,
          typename __detail::enable_if<
            __detail::is_convertible<_U&&, _T>::value,
          bool>::type = true
        >
        __UTILITY_CPP14_CONSTEXPR__
        propagate_const(_U&& _val):
          __val(algorithm::forward<_U>(_val))
        { }
        template<
          typename _U,
          typename __detail::enable_if<
            !is_propagate_const<_U>::value &&
            __detail::is_constructible<_T, _U&&>::value,
          bool>::type = true,
          typename __detail::enable_if<
            !__detail::is_convertible<_U&&, _T>::value,
          bool>::type = false
        >
        __UTILITY_CPP14_CONSTEXPR__
        explicit propagate_const(_U&& _val):
          __val(algorithm::forward<_U>(_val))
        { }

        propagate_const(const propagate_const&) = delete;

      public:
        __UTILITY_CPP14_CONSTEXPR__
        propagate_const& operator=(propagate_const&&) = default;

        template<
          typename _U,
          typename __detail::enable_if<
            !is_propagate_const<_U>::value &&
            __detail::is_assignable<_T, _U&&>::value,
          bool>::type = true
        >
        __UTILITY_CPP14_CONSTEXPR__
        propagate_const& operator=(_U&& _val)
        {
          using algorithm::forward;
          __val = forward<_U>(_val);
          return *this;
        }

        template<
          typename _U,
          typename __detail::enable_if<
            __detail::is_assignable<_T, _U&&>::value,
          bool>::type = true
        >
        __UTILITY_CPP14_CONSTEXPR__
        propagate_const& operator=(propagate_const<_U>&& _other)
        {
          using algorithm::move;
          __val = move(_other.__val);
          return *this;
        }

        propagate_const& operator=(const propagate_const&) = delete;

      public:
        __UTILITY_CPP14_CONSTEXPR__
        element_type& operator*()
        { return *__detail::__get<element_type>(__val);}
        __UTILITY_CPP14_CONSTEXPR__
        const element_type& operator*() const
        { return *__detail::__get<element_type>(__val);}
        __UTILITY_CPP14_CONSTEXPR__
        element_type* operator->()
        { return __detail::__get<element_type>(__val);}
        __UTILITY_CPP14_CONSTEXPR__
        const element_type* operator->() const
        { return __detail::__get<element_type>(__val);}

      public:
        __UTILITY_CPP14_CONSTEXPR__
        element_type* get()
        { return __detail::__get<element_type>(__val);}
        __UTILITY_CPP14_CONSTEXPR__
        const element_type* get() const
        { return __detail::__get<element_type>(__val);}
        __UTILITY_CPP14_CONSTEXPR__
        _T& get_underlying() noexcept
        { return __val;}
        __UTILITY_CPP14_CONSTEXPR__
        const _T& get_underlying() const noexcept
        { return __val;}

      public:
        __UTILITY_CPP14_CONSTEXPR__
        explicit operator bool() const
        { return __detail::__has(__val);}
        template<
          typename _Check = bool,
          typename __detail::enable_if<
            __detail::is_convertible<_T, element_type*>::value,
          _Check>::type = true
        >
        __UTILITY_CPP14_CONSTEXPR__
        operator element_type*()
        { return __detail::__get<element_type>(__val);}
        template<
          typename _Check = bool,
          typename __detail::enable_if<
            __detail::is_convertible<const _T, const element_type*>::value,
          _Check>::type = true
        >
        __UTILITY_CPP14_CONSTEXPR__
        operator const element_type*() const
        { return __detail::__get<element_type>(__val);}

      public:
        void swap(propagate_const& _other) noexcept(
          __detail::is_nothrow_swappable<_T>::value
        )
        {
          using algorithm::swap;
          swap(__val, _other.__val);
        }
        void possible_swap(propagate_const& _other) noexcept(
          __detail::is_nothrow_possible_swappable<_T>::value
        )
        {
          using algorithm::possible_swap;
          possible_swap(__val, _other.__val);
        }

    };

    template<typename _T>
    __UTILITY_CPP14_CONSTEXPR__
    _T& get_underlying(propagate_const<_T>& _pc) noexcept
    { return _pc.get_underlying();}
    template<typename _T>
    __UTILITY_CPP14_CONSTEXPR__
    const _T& get_underlying(const propagate_const<_T>& _pc) noexcept
    { return _pc.get_underlying();}

    template<typename _T>
    __UTILITY_CPP14_CONSTEXPR__
    bool operator==(const propagate_const<_T>& _x, nullptr_t)
    { return _x.get_underlying() == nullptr;}
    template<typename _T>
    __UTILITY_CPP14_CONSTEXPR__
    bool operator==(nullptr_t, const propagate_const<_T>& _y)
    { return _y.get_underlying() == nullptr;}
    template<typename _T>
    __UTILITY_CPP14_CONSTEXPR__
    bool operator!=(const propagate_const<_T>& _x, nullptr_t)
    { return _x.get_underlying() != nullptr;}
    template<typename _T>
    __UTILITY_CPP14_CONSTEXPR__
    bool operator!=(nullptr_t, const propagate_const<_T>& _y)
    { return _y.get_underlying() != nullptr;}

    template<typename _T, typename _U>
    __UTILITY_CPP14_CONSTEXPR__
    bool operator==(
      const propagate_const<_T>& _x,
      const propagate_const<_U>& _y
    )
    { return _x.get_underlying() == _y.get_underlying();}
    template<typename _T, typename _U>
    __UTILITY_CPP14_CONSTEXPR__
    bool operator!=(
      const propagate_const<_T>& _x,
      const propagate_const<_U>& _y
    )
    { return _x.get_underlying() != _y.get_underlying();}
    template<typename _T, typename _U>
    __UTILITY_CPP14_CONSTEXPR__
    bool operator<(
      const propagate_const<_T>& _x,
      const propagate_const<_U>& _y
    )
    { return _x.get_underlying() < _y.get_underlying();}
    template<typename _T, typename _U>
    __UTILITY_CPP14_CONSTEXPR__
    bool operator>(
      const propagate_const<_T>& _x,
      const propagate_const<_U>& _y
    )
    { return _x.get_underlying() > _y.get_underlying();}
    template<typename _T, typename _U>
    __UTILITY_CPP14_CONSTEXPR__
    bool operator<=(
      const propagate_const<_T>& _x,
      const propagate_const<_U>& _y
    )
    { return _x.get_underlying() <= _y.get_underlying();}
    template<typename _T, typename _U>
    __UTILITY_CPP14_CONSTEXPR__
    bool operator>=(
      const propagate_const<_T>& _x,
      const propagate_const<_U>& _y
    )
    { return _x.get_underlying() >= _y.get_underlying();}

    template<typename _T, typename _U>
    __UTILITY_CPP14_CONSTEXPR__
    bool operator==(const propagate_const<_T>& _x, const _U& _y)
    { return _x.get_underlying() == _y;}
    template<typename _T, typename _U>
    __UTILITY_CPP14_CONSTEXPR__
    bool operator==(const _U& _x, const propagate_const<_U>& _y)
    { return _x == _y.get_underlying();}
    template<typename _T, typename _U>
    __UTILITY_CPP14_CONSTEXPR__
    bool operator!=(const propagate_const<_T>& _x, const _U& _y)
    { return _x.get_underlying() != _y;}
    template<typename _T, typename _U>
    __UTILITY_CPP14_CONSTEXPR__
    bool operator!=(const _U& _x, const propagate_const<_U>& _y)
    { return _x != _y.get_underlying();}
    template<typename _T, typename _U>
    __UTILITY_CPP14_CONSTEXPR__
    bool operator<(const propagate_const<_T>& _x, const _U& _y)
    { return _x.get_underlying() < _y;}
    template<typename _T, typename _U>
    __UTILITY_CPP14_CONSTEXPR__
    bool operator<(const _U& _x, const propagate_const<_U>& _y)
    { return _x < _y.get_underlying();}
    template<typename _T, typename _U>
    __UTILITY_CPP14_CONSTEXPR__
    bool operator>(const propagate_const<_T>& _x, const _U& _y)
    { return _x.get_underlying() > _y;}
    template<typename _T, typename _U>
    __UTILITY_CPP14_CONSTEXPR__
    bool operator>(const _U& _x, const propagate_const<_U>& _y)
    { return _x > _y.get_underlying();}
    template<typename _T, typename _U>
    __UTILITY_CPP14_CONSTEXPR__
    bool operator<=(const propagate_const<_T>& _x, const _U& _y)
    { return _x.get_underlying() <= _y;}
    template<typename _T, typename _U>
    __UTILITY_CPP14_CONSTEXPR__
    bool operator<=(const _U& _x, const propagate_const<_U>& _y)
    { return _x <= _y.get_underlying();}
    template<typename _T, typename _U>
    __UTILITY_CPP14_CONSTEXPR__
    bool operator>=(const propagate_const<_T>& _x, const _U& _y)
    { return _x.get_underlying() >= _y;}
    template<typename _T, typename _U>
    __UTILITY_CPP14_CONSTEXPR__
    bool operator>=(const _U& _x, const propagate_const<_U>& _y)
    { return _x >= _y.get_underlying();}

  __utility_interspace_end(wrapper)

  __utility_interspace_start(algorithm)
    template<typename _T>
    inline void swap(
      wrapper::propagate_const<_T>& _x, wrapper::propagate_const<_T>& _y
    ) noexcept(noexcept(_x.swap(_y)))
    { _x.swap(_y);}
    template<typename _T>
    inline void possible_swap(
      wrapper::propagate_const<_T>& _x, wrapper::propagate_const<_T>& _y
    ) noexcept(noexcept(_x.possible_swap(_y)))
    { _x.possible_swap(_y);}
  __utility_interspace_end(algorithm)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_WRAPPER_PROPAGATE_CONST__
