
#ifndef ___UTILITY__STANDARD__LIBRARY__CSTDIO___
#define ___UTILITY__STANDARD__LIBRARY__CSTDIO___

#include<utility/config/utility_config.hpp>
#include<stdio.h>

#if !defined(__UTILITY_BUILD_LIB) || !defined(__UTILITY_NO_SYSHEADER)
#pragma GCC system_header
#endif

#ifndef getc
#undef getc
#endif

#ifndef putc
#undef putc
#endif

#ifndef clearerr
#undef clearerr
#endif

#ifndef feof
#undef feof
#endif

#ifndef ferror
#undef ferror
#endif

__utility_globalspace_start(utility)
  namespace sstd
  {
    using ::FILE;
    using ::fpos_t;
    using ::size_t;

    using ::fclose;
    using ::fflush;
    using ::setbuf;
    using ::setvbuf;
    using ::fprintf;
    using ::fscanf;
    using ::snprintf;
    using ::sprintf;
    using ::sscanf;
    using ::vfprintf;
    using ::vfscanf;
    using ::vsscanf;
    using ::vsnprintf;
    using ::vsprintf;
    using ::fgetc;
    using ::fgets;
    using ::fputc;
    using ::fputs;
    using ::getc;
    using ::putc;
    using ::ungetc;
    using ::fread;
    using ::fwrite;
    using ::fgetpos;
    using ::fseek;
    using ::fsetpos;
    using ::ftell;
    using ::rewind;
    using ::clearerr;
    using ::feof;
    using ::ferror;
    using ::perror;

#ifndef __UTILITY_NO_C_FILESYSTEM
    using ::fopen;
    using ::freopen;
    using ::remove;
    using ::rename;
    using ::tmpfile;
    using ::tmpnam;
#endif

#ifndef __UTILITY_NO_STDIN
    using ::getchar;
#if defined(__UTILITY_NO_CPP14__) && !defined(_LIBCPP_MSVCRT)
    using ::gets;
#endif
    using ::scanf;
    using ::vscanf;
#endif // ! __UTILITY_NO_STDIN

#ifndef __UTILITY_NO_STDOUT
    using ::printf;
    using ::putchar;
    using ::puts;
    using ::vprintf;
#endif // ! __UTILITY_NO_STDOUT
  }
__utility_globalspace_end(utility)

#endif // ! ___UTILITY__STANDARD__LIBRARY__CSTDIO___
