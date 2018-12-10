
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace sstd
  {
    void* memmem(void* _src, size_t _slen, const void* _pat, size_t _plen) noexcept
    {
      if(_src == nullptr || _pat == nullptr)
      { return _src;}
      if(_plen == 0)
      { return _src;}
      if(_slen < _plen)
      { return nullptr;}
      const unsigned char* __mem_tag =
        static_cast<const unsigned char*>(_pat);
      unsigned char* __src = static_cast<unsigned char*>(_src);
      unsigned char* __endsrc = __src +(_slen - _plen) +1;
      if(_plen == 1)
      { return memchr(_src, *__mem_tag, _slen);}
      for(; __src < __endsrc;)
      {
        if((*__src == *__mem_tag) && (memcmp(__src, __mem_tag, _plen) == 0))
        { return __src;}
        ++__src;
      }
      return nullptr;
    }
    const void* memmem(const void* _src, size_t _slen, const void* _pat, size_t _plen) noexcept
    {
      if(_src == nullptr || _pat == nullptr)
      { return _src;}
      if(_plen == 0)
      { return _src;}
      if(_slen < _plen)
      { return nullptr;}
      const unsigned char* __mem_tag = static_cast<const unsigned char*>(_pat);
      const unsigned char* __src = static_cast<const unsigned char*>(_src);
      const unsigned char* __endsrc = __src +(_slen - _plen) +1;
      if(_plen == 1)
      { return memchr(_src, *__mem_tag, _slen);}
      for(; __src < __endsrc;)
      {
        if((*__src == *__mem_tag) && (memcmp(__src, __mem_tag, _plen) == 0))
        { return __src;}
        ++__src;
      }
      return nullptr;
    }

  }
}
