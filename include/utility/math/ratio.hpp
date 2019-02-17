
#ifndef __UTILITY_MATH_RATIO__
#define __UTILITY_MATH_RATIO__

#include<utility/config/utility_config.hpp>
#include<utility/math/math_helper.hpp>

#include<utility/sstd/cstdint.hpp>
#include<utility/trait/trait_helper.hpp>


__utility_globalspace_start(utility)
  __utility_interspace_start(math)
  template<intmax_t _Num, intmax_t _Denom = 1>
  struct ratio;

  namespace __detail
  {
    template<intmax_t _X, intmax_t _Y>
    struct __int_gcd
    { constexpr static intmax_t value = __int_gcd<_Y, _X % _Y>::value;};
    template<intmax_t _X>
    struct __int_gcd<_X, 0>
    { constexpr static intmax_t value = _X;};
    template<>
    struct __int_gcd<0, 0>
    { constexpr static intmax_t value = 1LL;};

    template<intmax_t _X>
    struct __int_abs
    { constexpr static intmax_t value = _X < 0 ? -_X :_X;};

    template<intmax_t _X>
    struct __int_sign
    { constexpr static intmax_t value = _X == 0 ? 0 : _X < 0 ? -1 : 1;};

    template<intmax_t _X>
    struct __ratio_request
    { constexpr static bool value = _X != INTMAX_MIN;};

    template<intmax_t _X, intmax_t _Y>
    struct __int_multiply
    {
      static_assert(__ratio_request<_X>::value, "_X out of range");
      static_assert(__ratio_request<_Y>::value, "_Y out of range");
      constexpr static intmax_t X_abs = __int_abs<_X>::value;
      constexpr static intmax_t Y_abs = __int_abs<_Y>::value;

      static_assert(Y_abs > INTMAX_MAX / X_abs, "multiply overflow");
      static_assert(
        (Y_abs == INTMAX_MAX / X_abs) && (INTMAX_MAX % X_abs != 0),
        "multiply overflow"
      );

      constexpr static intmax_t value = _X * _Y;
    };
    template<intmax_t _X>
    struct __int_multiply<_X, 0>
    { constexpr static intmax_t value = 0;};
    template<intmax_t _Y>
    struct __int_multiply<0, _Y>
    { constexpr static intmax_t value = 0;};
    template<>
    struct __int_multiply<0, 0>
    { constexpr static intmax_t value = 0;};

    template<intmax_t _X, intmax_t _Y>
    struct __int_add
    {
      static_assert(__ratio_request<_X>::value, "_X out of range");
      static_assert(__ratio_request<_Y>::value, "_Y out of range");
      constexpr static intmax_t X_abs = __int_abs<_X>::value;
      constexpr static intmax_t Y_abs = __int_abs<_Y>::value;
      constexpr static intmax_t X_sign = __int_sign<_X>::value;
      constexpr static intmax_t Y_sign = __int_sign<_Y>::value;

      static_assert(
        X_sign != Y_sign || !(X_abs + Y_abs < X_abs),
        "add overflow"
      );
      constexpr static intmax_t value = _X + _Y;
    };
  }

  template<intmax_t _Num, intmax_t _Denom>
  struct ratio
  {
    private:
      static_assert(
        __detail::__ratio_request<_Num>::value,
        "_Num can not be INTMAX_MIN"
      );
      static_assert(
        __detail::__ratio_request<_Denom>::value,
        "_Denom can not be INTMAX_MIN"
      );
      static_assert(_Denom != 0, "_Denom can not be 0");

    private:
      constexpr static intmax_t num_abs =
        __detail::__int_abs<_Num>::value;
      constexpr static intmax_t den_abs =
        __detail::__int_abs<_Denom>::value;
      constexpr static intmax_t gcd_v =
        __detail::__int_gcd<num_abs, den_abs>::value;
      constexpr static intmax_t num_sign =
        __detail::__int_sign<_Num>::value *
        __detail::__int_sign<_Denom>::value;

    public:
      constexpr static intmax_t num = num_abs / gcd_v * num_sign;
      constexpr static intmax_t den = den_abs / gcd_v;
      typedef ratio<num, den> type;
  };

  typedef ratio<1LL, 1000000000000000000LL> atto;
  typedef ratio<1LL,    1000000000000000LL> femto;
  typedef ratio<1LL,       1000000000000LL> pico;
  typedef ratio<1LL,          1000000000LL> nano;
  typedef ratio<1LL,             1000000LL> micro;
  typedef ratio<1LL,                1000LL> milli;
  typedef ratio<1LL,                 100LL> centi;
  typedef ratio<1LL,                  10LL> deci;
  typedef ratio<                 10LL, 1LL> deca;
  typedef ratio<                100LL, 1LL> hecto;
  typedef ratio<               1000LL, 1LL> kilo;
  typedef ratio<            1000000LL, 1LL> mega;
  typedef ratio<         1000000000LL, 1LL> giga;
  typedef ratio<      1000000000000LL, 1LL> tera;
  typedef ratio<   1000000000000000LL, 1LL> peta;
  typedef ratio<1000000000000000000LL, 1LL> exa;

  namespace __detail
  {
    template<typename _X>
    struct __ratio_abs
    { typedef typename ratio<__int_abs<_X::num>::value, _X::den>::type type;};

    template<typename _X>
    struct __ratio_reciprocal
    { typedef typename ratio<_X::den, _X::num>::type type;};

    template<typename _X>
    struct __ratio_minus
    { typedef typename ratio<-_X::num, _X::den>::type type;};


    template<typename _X, typename _Y>
    struct __ratio_add
    {
      constexpr static intmax_t gcd_v = __int_gcd<_X::den, _Y::den>::value;
      constexpr static intmax_t lcm_v = __int_multiply<_X::den / gcd_v, _Y::den>::value;
      typedef typename ratio<
        __int_add<
          __int_multiply<_X::num, lcm_v / _X::den>::value,
          __int_multiply<_Y::num, lcm_v / _Y::den>::value
        >::value,
        lcm_v
      >::type type;
    };

    template<typename _X, typename _Y>
    struct __ratio_multiply
    {
      constexpr static intmax_t X_abs = __int_abs<_X::num>::value;
      constexpr static intmax_t Y_abs = __int_abs<_Y::num>::value;
      constexpr static intmax_t X_sign =
       __int_sign<_X::num>::value * __int_sign<_Y::num>::value;
      constexpr static intmax_t gcd_X = __int_gcd<_X::num, _Y::den>::value;
      constexpr static intmax_t gcd_Y = __int_gcd<_Y::num, _X::den>::value;
      typedef typename ratio<
        __int_multiply<_X::num / gcd_X, _Y::num / gcd_Y>::value,
        __int_multiply<_X::den / gcd_Y, _Y::den / gcd_X>::value
      >::type type;
    };

    template<typename _X>
    struct __ratio_trunc
    { typedef typename ratio<_X::num / _X::den, 1>::type type;};

  }

  template<typename _X>
  using ratio_abs = typename __detail::__ratio_abs<_X>::type;
  template<typename _X>
  using ratio_reciprocal = typename __detail::__ratio_reciprocal<_X>::type;
  template<typename _X>
  using ratio_minus = typename __detail::__ratio_minus<_X>::type;

  template<typename _X, typename _Y>
  using ratio_add = typename __detail::__ratio_add<_X, _Y>::type;
  template<typename _X, typename _Y>
  using  ratio_subtract = typename __detail::__ratio_add<
    _X, ratio_minus<_Y>
  >::type;
  template<typename _X, typename _Y>
  using ratio_multiply = typename __detail::__ratio_multiply<
    _X, _Y
  >::type;
  template<typename _X, typename _Y>
  using ratio_divide = typename __detail::__ratio_multiply<
    _X, ratio_reciprocal<_Y>
  >::type;

  template<typename _X>
  using ratio_trunc = typename __detail::__ratio_trunc<_X>::type;
  template<typename _X>
  struct ratio_div
  {
    typedef typename ratio<_X::num / _X::den, 1>::type       integral;
    typedef typename ratio<_X::num % _X::den, _X::den>::type fractional;
  };


  namespace __detail
  {
    template<typename _X, typename _Y>
    struct __ratio_compare;

    template<
      int, typename _X, typename _Y,
      intmax_t _X_num, intmax_t _X_den, intmax_t _Y_num, intmax_t _Y_den
    >
    struct __ratio_compare_fractional
    {
      constexpr static int value = __ratio_compare<
        ratio_reciprocal<_Y>, ratio_reciprocal<_X>
      >::value;
    };

    template<
      typename _X, typename _Y,
      intmax_t _X_num, intmax_t _Den, intmax_t _Y_num
    >
    struct __ratio_compare_fractional<0, _X, _Y, _X_num,_Den, _Y_num,_Den>
    { constexpr static int value = __int_sign<_X_num - _Y_num>::value;};

    template<
      typename _X, typename _Y,
      intmax_t _X_den, intmax_t _Y_num, intmax_t _Y_den
    >
    struct __ratio_compare_fractional<0, _X, _Y, 0,_X_den, _Y_num,_Y_den>
    { constexpr static int value = -__int_sign<_Y_num>::value;};

    template<
      typename _X, typename _Y,
      intmax_t _X_num, intmax_t _X_den, intmax_t _Y_den
    >
    struct __ratio_compare_fractional<0, _X, _Y, _X_num,_X_den, 0,_Y_den>
    { constexpr static int value = __int_sign<_X_num>::value;};

    template<
      typename _X, typename _Y,
      intmax_t _X_den, intmax_t _Y_den
    >
    struct __ratio_compare_fractional<0, _X, _Y, 0,_X_den, 0,_Y_den>
    { constexpr static int value = 0;};

    template<
      typename _X, typename _Y,
      intmax_t _X_num, intmax_t _X_den,
      intmax_t _Y_num, intmax_t _Y_den
    >
    struct __ratio_compare_fractional<1, _X, _Y, _X_num,_X_den, _Y_num,_Y_den>
    { constexpr static int value = 1;};

    template<
      typename _X, typename _Y,
      intmax_t _X_num, intmax_t _X_den,
      intmax_t _Y_num, intmax_t _Y_den
    >
    struct __ratio_compare_fractional<-1,  _X, _Y, _X_num,_X_den, _Y_num,_Y_den>
    { constexpr static int value = -1;};

    template<typename _X, typename _Y>
    struct __ratio_compare
    {
      typedef ratio_div<_X> X_div;
      typedef ratio_div<_Y> Y_div;

      constexpr static int value = __ratio_compare_fractional<
        __int_sign<X_div::integral::num - Y_div::integral::num>::value,
        typename X_div::fractional,
        typename Y_div::fractional,
        X_div::fractional::num,
        X_div::fractional::den,
        Y_div::fractional::num,
        Y_div::fractional::den
      >::value;
    };
  }

  template<typename _X, typename _Y>
  struct ratio_compare: public trait::integral_constant<
      int, __detail::__ratio_compare<_X, _Y>::value
    >
  { };

  template<typename _X, typename _Y>
  struct ratio_equal: public trait::bool_constant<
      ratio_compare<_X, _Y>::value == 0
    >
  { };
  template<typename _X, typename _Y>
  struct ratio_not_equal: public trait::bool_constant<
      ratio_compare<_X, _Y>::value != 0
    >
  { };
  template<typename _X, typename _Y>
  struct ratio_less: public trait::bool_constant<
      (ratio_compare<_X, _Y>::value < 0)
    >
  { };
  template<typename _X, typename _Y>
  struct ratio_less_equal: public trait::bool_constant<
      (ratio_compare<_X, _Y>::value <= 0)
    >
  { };
  template<typename _X, typename _Y>
  struct ratio_greater: public trait::bool_constant<
      (0 < ratio_compare<_X, _Y>::value)
    >
  { };
  template<typename _X, typename _Y>
  struct ratio_greater_equal: public trait::bool_constant<
      (0 <= ratio_compare<_X, _Y>::value)
    >
  { };

  __utility_interspace_end(math)
__utility_globalspace_end(utility)


#endif // ! __UTILITY_MATH_RATIO__
