

#ifndef ___UTILITY__TYPE__DECLARARTION___
#define ___UTILITY__TYPE__DECLARARTION___

namespace utility
{
  using size_t = decltype(sizeof(char));  ///< size type
  using nullptr_t = decltype(nullptr);    ///< nullptr type
  using ptrdiff_t = decltype(reinterpret_cast<char*>(0)-reinterpret_cast<char*>(0));         ///< pointer storage type

  namespace _impl
  {
    template<typename>
    struct __ssize_t
    { typedef signed int type;};
    template<>
    struct __ssize_t<unsigned int>
    { typedef signed int type;};
    template<>
    struct __ssize_t<unsigned long>
    { typedef signed long type;};
    template<>
    struct __ssize_t<unsigned long long>
    { typedef signed long long type;};

    template<typename>
    struct __uptrdiff_t
    { typedef unsigned int type;};
    template<>
    struct __uptrdiff_t<signed int>
    { typedef unsigned int type;};
    template<>
    struct __uptrdiff_t<signed long>
    { typedef unsigned long type;};
    template<>
    struct __uptrdiff_t<signed long long>
    { typedef unsigned long long type;};
  }

  using ssize_t = typename _impl::__ssize_t<size_t>::type;
  using uptrdiff_t = typename _impl::__uptrdiff_t<ptrdiff_t>::type;
}

#endif // ! ___UTILITY__TYPE__DECLARARTION___
