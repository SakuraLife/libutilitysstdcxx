#include"builtin_function.h"


#define _LWORD(_VAL, _SHADOW)   ((_VAL) & (_SHADOW))
#define _HWORD(_VAL, _SHIFT)    ((_VAL) >> (_SHIFT))

__utility_globalspace_start(utility)
unsigned long _builtin::_mul_overflow_word(
  unsigned long _x, unsigned long _y, unsigned long* _val
) noexcept
{
  _ul __hx = _HWORD(_x, _bul/2);
  _ul __lx = _LWORD(_x, _lul);
  _ul __hy = _HWORD(_y, _bul/2);
  _ul __ly = _LWORD(_y, _lul);

  _ul __hxhy = __hx * __hy;
  _ul __hxly = __hx * __ly;
  _ul __lxhy = __lx * __hy;
  _ul __lxly = __lx * __ly;

  _ul __carry = _HWORD(
    _LWORD(__hxly, _lul) + _LWORD(__lxhy, _lul) + _HWORD(__lxly, _bul/2),
    _bull/2
  );

  *_val = _x * _y;

  return __hxhy + _HWORD(__lxhy, _bull/2) + _HWORD(__hxly, _bull/2) + __carry;
}

unsigned long long _builtin::_mul_overflow_word(
  unsigned long long _x, unsigned long long _y, unsigned long long* _val
) noexcept
{
  _ull __hx = _HWORD(_x, _bul/2);
  _ull __lx = _LWORD(_x, _lul);
  _ull __hy = _HWORD(_y, _bul/2);
  _ull __ly = _LWORD(_y, _lul);

  _ull __hxhy = __hx * __hy;
  _ull __hxly = __hx * __ly;
  _ull __lxhy = __lx * __hy;
  _ull __lxly = __lx * __ly;

  _ull __carry = _HWORD(
    _LWORD(__hxly, _lull) + _LWORD(__lxhy, _lull) + _HWORD(__lxly, _bull/2),
    _bull/2
  );

  *_val = _x * _y;

  return __hxhy + _HWORD(__lxhy, _bull/2) + _HWORD(__hxly, _bull/2) + __carry;
}
__utility_globalspace_end(utility)
