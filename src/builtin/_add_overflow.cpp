#include"builtin_function.h"

__utility_globalspace_start(utility)
bool _builtin::_add_overflow(
  unsigned char _x, unsigned char _y, unsigned char* _val
) noexcept
{
  _uc _res = _x + _y;
  if(_val)
  { *_val = _res;}
  return _res < _x;
}

bool _builtin::_add_overflow(
  unsigned short _x, unsigned short _y, unsigned short* _val
) noexcept
{
  _us _res = _x + _y;
  if(_val)
  { *_val = _res;}
  return _res < _x;
}
bool _builtin::_add_overflow(
  unsigned int _x, unsigned int _y, unsigned int* _val
) noexcept
{
  _ui _res = _x + _y;
  if(_val)
  { *_val = _res;}
  return _res < _x;
}
bool _builtin::_add_overflow(
  unsigned long _x, unsigned long _y, unsigned long* _val
) noexcept
{
  _ul _res = _x + _y;
  if(_val)
  { *_val = _res;}
  return _res < _x;
}
bool _builtin::_add_overflow(
  unsigned long long _x, unsigned long long _y, unsigned long long* _val
) noexcept
{
  _ull _res = _x + _y;
  if(_val)
  { *_val = _res;}
  return _res < _x;
}
__utility_globalspace_end(utility)

