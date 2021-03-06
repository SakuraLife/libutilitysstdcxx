

#ifndef ___UTILITY__CONFIG___
#define ___UTILITY__CONFIG___

#ifndef __cplusplus
# error This is a C++ library , please use C++ compiler.
#endif
// add C++11 error
#if __cplusplus < 201103L
# include<utility/config/utility_cpp11_error.hpp>
#endif

#if __cplusplus < 201402L
# define __UTILITY_NO_CPP14__ true
#endif

#if __cplusplus < 201703L
# define __UTILITY_NO_CPP17__ true
#endif

#if __cplusplus < 202013L
# define __UTILITY_NO_CPP20__ true
#endif

#ifdef __cpp_concepts
#define __UTILITY_CPP_CONCEPTS__ __cpp_concepts
#endif

#ifndef __UTILITY_NO_CPP14__
# define __UTILITY_CPP14_CONSTEXPR__ constexpr
# define __UTILITY_CPP14_ATTRIBUTE__(_attr) [[_attr]]
#else
# define __UTILITY_CPP14_CONSTEXPR__
# define __UTILITY_CPP14_ATTRIBUTE__(_attr)
#endif // ! __UTILITY_NO_CPP14__

#ifndef __UTILITY_NO_CPP17__
# define __UTILITY_CPP17_CONSTEXPR__ constexpr
# define __UTILITY_CPP17_INLINE__ inline
# define __UTILITY_CPP17_ATTRIBUTE__(_attr) [[_attr]]
#else
# define __UTILITY_CPP17_CONSTEXPR__
# define __UTILITY_CPP17_INLINE__
# define __UTILITY_CPP17_ATTRIBUTE__(_attr)
#endif // ! __UTILITY_NO_CPP17__

#ifndef __UTILITY_NO_CPP20__
# define __UTILITY_CPP20_CONSTEXPR__ constexpr
# define __UTILITY_CPP20_ATTRIBUTE__(_attr) [[_attr]]
# define UTLITY_CPP20_TYPENAME(...) typename
#else
# define __UTILITY_CPP20_CONSTEXPR__
# define __UTILITY_CPP20_ATTRIBUTE__(_attr)
# define UTLITY_CPP20_TYPENAME(...) __VA_ARGS__
#endif // ! __UTILITY_NO_CPP17__

#define UTILITY_RELEASE         0L
#define UTILITY_INTERFACE       4L
#define UTILITY_INCREMENTAL     0L
#define UTILITY_VERSION \
  (UTILITY_INCREMENTAL + UTILITY_INTERFACE * 100L + UTILITY_RELEASE * 10000L)

// utility preconfig generate by system.
// will used if need.
// #include<utility/config/utility_preconfig.hpp>

#ifdef UTILITY_USE_HEADERS
#define __utility_inline inline
#else
#define __utility_inline
#endif // ! UTILITY_USE_HEADERS

#ifndef __has_attribute
#define __has_attribute(__x) 0
#endif

#ifndef __has_builtin
#define __has_builtin(__x) 0
#endif

#ifndef __has_extension
#define __has_extension(__x) 0
#endif

#ifndef __has_feature
#define __has_feature(__x) 0
#endif

#ifndef __has_cpp_attribute
#define __has_cpp_attribute(__x) 0
#endif

#ifndef __is_identifier
#define __is_identifier(__x) 1
#endif

#ifndef __has_declspec_attribute
#define __has_declspec_attribute(__x) 0
#endif

#define __has_keyword(__x) !(__is_identifier(__x))

#ifndef __has_include
#define __has_include(...) 0
#endif

// select the support compiler
#include<utility/config/compiler/select.hpp>

#include<utility/config/utility_visibility_config.hpp>
#include<utility/config/debug/utility_debug_config.hpp>

#if defined(UTILITY_NO_EXCEPTION)
# define __UTILITY_NO_EXCEPTION__ true
#endif

// utility exception config
#include<utility/config/utility_exception_config.hpp>

/*
// utility endian config
#ifdef __BIG_ENDIAN__
#if __BIG_ENDIAN__
#define __UTILITY_BIG_ENDIAN__    1
#define __UTILITY_LITTLE_ENDIAN__ 0
#endif // ! __BIG_ENDIAN__
#endif // ! __BIG_ENDIAN__
#ifdef __LITTLE_ENDIAN__
#if __LITTLE_ENDIAN__
#define __UTILITY_BIG_ENDIAN__    0
#define __UTILITY_LITTLE_ENDIAN__ 1
#endif // ! __LITTLE_ENDIAN__
#endif // ! __LITTLE_ENDIAN__
#ifdef __BYTE_ORDER__
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define __UTILITY_BIG_ENDIAN__    0
#define __UTILITY_LITTLE_ENDIAN__ 1
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#define __UTILITY_BIG_ENDIAN__    1
#define __UTILITY_LITTLE_ENDIAN__ 0
#endif // __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#endif // __BYTE_ORDER__
*/

// get std support config
#include<utility/config/utility_control_config.hpp>

// utility global type declaration
#include<utility/config/utility_type.hpp>

// utility extra config
#include<utility/config/extra/utility_algorithm_extra.hpp>
#include<utility/config/extra/utility_container_extra.hpp>
#include<utility/config/extra/utility_iterator_extra.hpp>
#include<utility/config/extra/utility_math_extra.hpp>
#include<utility/config/extra/utility_memory_extra.hpp>
#include<utility/config/extra/utility_trait_extra.hpp>

#endif // ! ___UTILITY__CONFIG__
