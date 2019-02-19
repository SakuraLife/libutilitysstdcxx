
#ifndef __UTILITY_TRAIT_INTEGRAL_CONSTANT__
#define __UTILITY_TRAIT_INTEGRAL_CONSTANT__

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    // helper class and declaration
    template<typename _type, _type _val>
    struct __UTILITY_TYPE_VIS integral_constant
    {
      constexpr static _type value = _val;
      typedef _type value_type;
      typedef integral_constant<_type, _val> type;
      constexpr operator value_type() const noexcept
      { return value;}
      constexpr value_type operator()() const noexcept
      { return value;}

    };
    template<bool _B>
    using bool_constant = integral_constant<bool, _B>;
    using true_type   = bool_constant<true>;
    using false_type  = bool_constant<false>;

  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_TRAIT_INTEGRAL_CONSTANT__
