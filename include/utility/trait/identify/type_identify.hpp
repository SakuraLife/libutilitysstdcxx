
#ifndef ___UTILITY__TRAIT__TYPE__IDENTIFT___
#define ___UTILITY__TRAIT__TYPE__IDENTIFT___

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/type/type_features.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(identify)
      template<typename _T>
      class __UTILITY_TEMPLATE_VIS type_identification
      {
        // using namespace trait::type::features;
        public:
          typedef _T            type;
          typedef const _T      const_type;
          typedef _T*           pointer;
          typedef const _T*     const_pointer;
          typedef volatile _T*  volatile_pointer;
          typedef _T&           lvalue_reference;
          typedef _T&&          rvalue_reference;

        public:
          constexpr static bool is_specific = false;

        public:

          using has_trivial_default_constructor =
          trait::type::features::is_trivially_default_constructible<_T>;
          template<typename... _Args>
          using has_constructor =
          trait::type::features::is_constructible<_T, _Args...>;

      };
    __utility_interspace_end(identify)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // ! ___UTILITY__TRAIT__TYPE__IDENTIFT___
