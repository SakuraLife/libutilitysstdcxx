
#ifndef ___UTILITY__STANDARD__LIBRARRY__STDARG___
#define ___UTILITY__STANDARD__LIBRARRY__STDARG___

#if defined(__GNUC__) || defined(__clang__)
#define ___UTILITY_va_list                __builtin_va_list
#define ___UTILITY_va_arg(_ap, _type)     (__builtin_va_arg((_ap), _type))
#define ___UTILITY_va_copy(_dest, _src)   (__builtin_va_copy((_dest), (_src)))
#define ___UTILITY_va_end(_ap)            (__builtin_va_end(_ap))
#define ___UTILITY_va_start(_ap, _pnum)   (__builtin_va_start((_ap), (_pnum)))

#elif (defined(__i386__) || defined(__i386) || defined(_M_IX86)) && \
      !(defined(__amd64__) || defined(__x86_64__) || defined(_M_AMD64))
#define ___UTILITY_va_round(_type) ((sizeof(_type) + sizeof(void *) - 1) & ~(sizeof(void *) - 1))
#define ___UTILITY_va_list                char*
#define ___UTILITY_va_arg(_ap, _type)     ((_ap) += (___UTILITY_va_round(_type)), (*(_type*) ((_ap) - (___UTILITY_va_round(_type)))))
#define ___UTILITY_va_copy(_dest, _src)   ((_dest) = (_src), nullptr)
#define ___UTILITY_va_end(_ap)            ((_ap) =  (void*)0, nullptr)
#define ___UTILITY_va_start(_ap, _pnum)   ((_ap) = (char*) &_pnum + (___UTILITY_va_round(_pnum)), nullptr)
#else
#error Compiler/Architecture not support ! Please edit it to fix or disable.
#endif


#endif // ! ___UTILITY__STANDARD__LIBRARRY__STDARG___
