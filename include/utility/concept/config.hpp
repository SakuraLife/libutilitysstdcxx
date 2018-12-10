
#ifndef ___UTILITY__CONCEPT__CONFIG___
#define ___UTILITY__CONCEPT__CONFIG___

#include<utility/config/utility_config.hpp>

#if defined(__UTILITY_NO_CPP20__)
#define __utility_has_concept false
#define __utility_require(...)
#else
#define __utility_has_concept true
#define __utility_require(...) requires __VA_ARGS__
#endif // ! __UTILITY_NO_CPP20__

#endif // ! ___UTILITY__CONCEPT__CONFIG___
