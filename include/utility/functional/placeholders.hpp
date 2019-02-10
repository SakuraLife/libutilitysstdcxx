
#ifndef __UTILITY_FUNCTIONAL_PLACEHOLDERS__
#define __UTILITY_FUNCTIONAL_PLACEHOLDERS__

#include<utility/trait/trait_helper.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(functional)
    namespace placeholders
    {
      template<int _ID>
      struct phid
      { };

      __UTILITY_CPP17_INLINE__
      constexpr phid<1> _1{};
      __UTILITY_CPP17_INLINE__
      constexpr phid<2> _2{};
      __UTILITY_CPP17_INLINE__
      constexpr phid<3> _3{};
      __UTILITY_CPP17_INLINE__
      constexpr phid<4> _4{};
      __UTILITY_CPP17_INLINE__
      constexpr phid<5> _5{};
      __UTILITY_CPP17_INLINE__
      constexpr phid<6> _6{};
      __UTILITY_CPP17_INLINE__
      constexpr phid<7> _7{};
      __UTILITY_CPP17_INLINE__
      constexpr phid<8> _8{};
      __UTILITY_CPP17_INLINE__
      constexpr phid<9> _9{};
      __UTILITY_CPP17_INLINE__
      constexpr phid<10> _10{};
      __UTILITY_CPP17_INLINE__
      constexpr phid<11> _11{};
      __UTILITY_CPP17_INLINE__
      constexpr phid<12> _12{};
      __UTILITY_CPP17_INLINE__
      constexpr phid<13> _13{};
      __UTILITY_CPP17_INLINE__
      constexpr phid<14> _14{};
      __UTILITY_CPP17_INLINE__
      constexpr phid<15> _15{};
      __UTILITY_CPP17_INLINE__
      constexpr phid<16> _16{};
      __UTILITY_CPP17_INLINE__
      constexpr phid<17> _17{};
      __UTILITY_CPP17_INLINE__
      constexpr phid<18> _18{};
      __UTILITY_CPP17_INLINE__
      constexpr phid<19> _19{};
      __UTILITY_CPP17_INLINE__
      constexpr phid<20> _20{};
    }

    template<typename _T>
    struct is_placeholder: public trait::integral_constant<int, 0>
    { };
    template<int _ID>
    struct is_placeholder<placeholders::phid<_ID>>:
      public trait::integral_constant<int, _ID>
    { };

    template<typename _T>
    struct is_placeholder<const _T>: public is_placeholder<_T>
    { };
    template<typename _T>
    struct is_placeholder<volatile _T>: public is_placeholder<_T>
    { };
    template<typename _T>
    struct is_placeholder<const volatile _T>: public is_placeholder<_T>
    { };
  __utility_interspace_end(functional)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_FUNCTIONAL_PLACEHOLDERS__
