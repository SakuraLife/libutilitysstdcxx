
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    wchar_t* wmemset(wchar_t* _wmem, wchar_t _wval, size_t _size) noexcept
    {
      if(_size && _wmem != nullptr)
      {
        for(; _size; --_size)
        { *_wmem++ = _wval;}
      }
      return _wmem;
    }

  }
}
