#ifndef ___UTILITY__STANDARD__LIBRARY__NEW___
#define ___UTILITY__STANDARD__LIBRARY__NEW___

#include<utility/config/utility_config.hpp>

#include<utility/trait/type/categories/is_function.hpp>
#include<utility/trait/type/transform/remove_cv.hpp>
#include<utility/trait/type/releations/is_same.hpp>

#include<utility/exception/exception.hpp>

#if !defined(__UTILITY_BUILD_LIB) || !defined(__UTILITY_NO_SYSHEADER)
#pragma GCC system_header
#endif

__utility_exceptspace_start(utility)
  enum class __UTILITY_ENUM_VIS align_val_t: __exceptspace(utility)::size_t
  { };

  struct __UTILITY_TYPE_VIS nothrow_t
  { };
  extern __UTILITY_FUNC_VIS const nothrow_t nothrow;

  typedef void (*new_handler)();
  __UTILITY_FUNC_VIS
  new_handler set_new_handler(new_handler) noexcept;
  __UTILITY_FUNC_VIS
  new_handler get_new_handler() noexcept;

  struct __UTILITY_TYPE_VIS destroying_delete_t
  { explicit destroying_delete_t() = default;};
  __UTILITY_CPP17_INLINE__
  constexpr destroying_delete_t destroying_delete{};

  class __UTILITY_EXCEPTION_ABI bad_alloc:
    public __exceptspace(utility)::exception
  {
    public:
      bad_alloc() noexcept;
      virtual ~bad_alloc() noexcept;
      virtual const char* what() const noexcept;
  };

  class __UTILITY_EXCEPTION_ABI bad_array_new_length:
    public __exceptspace(utility)::bad_alloc
  {
    public:
      bad_array_new_length() noexcept;
      virtual ~bad_array_new_length() noexcept;
      virtual const char* what() const noexcept;
  };

#ifndef __UTILITY_NO_CPP17__

  template <class _T>
  __UTILITY_CPP20_ATTRIBUTE__(nodiscard)
  inline constexpr _T* launder(_T* _ptr) noexcept
  {
    using __uspace(utility)::trait::type::categories::is_function;
    using __uspace(utility)::trait::type::releations::is_same;
    using __uspace(utility)::trait::type::transform::remove_cv_t;
    static_assert(!(is_function<_T>::value), "can't launder functions" );
    static_assert(!(is_same<void, remove_cv_t<_T>>::value), "can't launder cv-void" );
#if __has_builtin(__builtin_launder) || defined(__UTILITY_HAS_LAUNDER)
    return __builtin_launder(_ptr);
#else
    return _ptr;
#endif
  }

  // using __exceptspace(utility)::hardware_destructive_interference_size;
  // using __exceptspace(utility)::hardware_constructive_interference_size;

#endif
__utility_exceptspace_end(utility)

__UTILITY_CPP20_ATTRIBUTE__(nodiscard)
__UTILITY_OVERRIDABLE_FUNC_VIS
void* operator new(__exceptspace(utility)::size_t _count);
__UTILITY_CPP20_ATTRIBUTE__(nodiscard)
__UTILITY_OVERRIDABLE_FUNC_VIS
void* operator new(__exceptspace(utility)::size_t _count, const __exceptspace(utility)::nothrow_t&) noexcept;
__UTILITY_CPP20_ATTRIBUTE__(nodiscard)
__UTILITY_OVERRIDABLE_FUNC_VIS
inline void* operator new(__exceptspace(utility)::size_t, void* _ptr) noexcept
{ return _ptr;}

__UTILITY_CPP20_ATTRIBUTE__(nodiscard)
__UTILITY_OVERRIDABLE_FUNC_VIS
void* operator new[](__exceptspace(utility)::size_t _count);
__UTILITY_CPP20_ATTRIBUTE__(nodiscard)
__UTILITY_OVERRIDABLE_FUNC_VIS
void* operator new[](__exceptspace(utility)::size_t _count, const __exceptspace(utility)::nothrow_t&) noexcept;
__UTILITY_CPP20_ATTRIBUTE__(nodiscard)
__UTILITY_OVERRIDABLE_FUNC_VIS
void* operator new[](__exceptspace(utility)::size_t, void* _ptr) noexcept
{ return _ptr;}

__UTILITY_OVERRIDABLE_FUNC_VIS
void operator delete(void* _ptr) noexcept;
__UTILITY_OVERRIDABLE_FUNC_VIS
void operator delete(void* _ptr, const __exceptspace(utility)::nothrow_t&) noexcept;
__UTILITY_OVERRIDABLE_FUNC_VIS
void operator delete(void*, void*) noexcept
{ }

__UTILITY_OVERRIDABLE_FUNC_VIS
void operator delete[](void* _ptr) noexcept;
__UTILITY_OVERRIDABLE_FUNC_VIS
void operator delete[](void* _ptr, const __exceptspace(utility)::nothrow_t&) noexcept;
__UTILITY_OVERRIDABLE_FUNC_VIS
void operator delete[](void*, void*) noexcept
{ }

#ifndef __UTILITY_NO_CPP14__

__UTILITY_OVERRIDABLE_FUNC_VIS
void operator delete(void* _ptr, __exceptspace(utility)::size_t _count) noexcept;
__UTILITY_OVERRIDABLE_FUNC_VIS
void operator delete[](void* _ptr, __exceptspace(utility)::size_t _count) noexcept;

#endif // ! __UTILITY_NO_CPP14__

#ifndef __UTILITY_NO_CPP17__

__UTILITY_CPP20_ATTRIBUTE__(nodiscard)
__UTILITY_OVERRIDABLE_FUNC_VIS
void* operator new(__exceptspace(utility)::size_t _count, __exceptspace(utility)::align_val_t _al);
__UTILITY_CPP20_ATTRIBUTE__(nodiscard)
__UTILITY_OVERRIDABLE_FUNC_VIS
void* operator new(__exceptspace(utility)::size_t _count, __exceptspace(utility)::align_val_t _al, const __exceptspace(utility)::nothrow_t&) noexcept;

// __UTILITY_CPP20_ATTRIBUTE__(nodiscard)
// __UTILITY_OVERRIDABLE_FUNC_VIS
// void* operator new[](__exceptspace(utility)::size_t _count, __exceptspace(utility)::align_val_t _al) noexcept;
__UTILITY_CPP20_ATTRIBUTE__(nodiscard)
__UTILITY_OVERRIDABLE_FUNC_VIS
void* operator new[](__exceptspace(utility)::size_t _count, __exceptspace(utility)::align_val_t _al, const __exceptspace(utility)::nothrow_t&) noexcept;

__UTILITY_OVERRIDABLE_FUNC_VIS
void operator delete(void* _ptr, __exceptspace(utility)::align_val_t _al) noexcept;
__UTILITY_OVERRIDABLE_FUNC_VIS
void operator delete(void* _ptr, __exceptspace(utility)::size_t _count, __exceptspace(utility)::align_val_t _al) noexcept;
__UTILITY_OVERRIDABLE_FUNC_VIS
void operator delete(void* _ptr, __exceptspace(utility)::align_val_t _al, const __exceptspace(utility)::nothrow_t&) noexcept;

__UTILITY_OVERRIDABLE_FUNC_VIS
void operator delete[](void* _ptr, __exceptspace(utility)::align_val_t _al) noexcept;
__UTILITY_OVERRIDABLE_FUNC_VIS
void operator delete[](void* _ptr, __exceptspace(utility)::size_t _count, __exceptspace(utility)::align_val_t _al) noexcept;
__UTILITY_OVERRIDABLE_FUNC_VIS
void operator delete[](void* _ptr, __exceptspace(utility)::align_val_t _al, const __exceptspace(utility)::nothrow_t&) noexcept;

#endif // ! __UTILITY_NO_CPP17__

#ifndef __UTILITY_NO_CPP20__

#endif // ! __UTILITY_NO_CPP20__

#endif // ! ___UTILITY__STANDARD__LIBRARY__NEW___
