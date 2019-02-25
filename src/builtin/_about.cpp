#include"builtin_function.h"

#include<stdlib.h>
#include<stdio.h>

__utility_globalspace_start(utility)
extern void _builtin::_about() noexcept
{
  abort();
}
extern void _builtin::_about(const char* _info) noexcept
{
  fprintf(stderr, "%s\n", _info);
  abort();
}
__utility_globalspace_end(utility)

