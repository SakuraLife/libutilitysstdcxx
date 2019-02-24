
#ifndef ___UTILITY__STANDARD__LIBRARY__CSTDBOOL___
#define ___UTILITY__STANDARD__LIBRARY__CSTDBOOL___

#include<utility/config/utility_config.hpp>

#if !defined(__UTILITY_BUILD_LIB) || !defined(__UTILITY_NO_SYSHEADER)
#pragma GCC system_header
#endif

#undef bool
#undef true
#undef false
#undef __bool_true_false_are_defined
#define __bool_true_false_are_defined 1

#endif // ! ___UTILITY__STANDARD__LIBRARY__CSTDBOOL___
