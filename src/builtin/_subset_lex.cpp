
#include"builtin_function.h"

template<typename _I>
static inline _I subset_lex_next(_I _val) noexcept
{
  _I __vl = _val & (-_val);
  if(__vl == 1)
  { return _val ^ (__vl >> 1);}
  _val ^= 1;
  return _val - ((_val & (-_val)) >> 1);
}

template<typename _I>
static inline _I subset_lex_prev(_I _val) noexcept
{
  _I __vl = _val & (-_val);
  if((__vl << 1) & _val)
  { return _val ^ __vl;}
  return (_val + __vl) | 1;
}

__utility_globalspace_start(utility)
unsigned char _builtin::_lex_next(unsigned char _val) noexcept
{ return subset_lex_next<_uc>(_val);}
unsigned short _builtin::_lex_next(unsigned short _val) noexcept
{ return subset_lex_next<_us>(_val);}
unsigned int _builtin::_lex_next(unsigned int _val) noexcept
{ return subset_lex_next<_ui>(_val);}
unsigned long _builtin::_lex_next(unsigned long _val) noexcept
{ return subset_lex_next<_ul>(_val);}
unsigned long long _builtin::_lex_next(unsigned long long _val) noexcept
{ return subset_lex_next<_ull>(_val);}

unsigned char _builtin::_lex_prev(unsigned char _val) noexcept
{ return subset_lex_prev<_uc>(_val);}
unsigned short _builtin::_lex_prev(unsigned short _val) noexcept
{ return subset_lex_prev<_us>(_val);}
unsigned int _builtin::_lex_prev(unsigned int _val) noexcept
{ return subset_lex_prev<_ui>(_val);}
unsigned long _builtin::_lex_prev(unsigned long _val) noexcept
{ return subset_lex_prev<_ul>(_val);}
unsigned long long _builtin::_lex_prev(unsigned long long _val) noexcept
{ return subset_lex_prev<_ull>(_val);}
__utility_globalspace_end(utility)
