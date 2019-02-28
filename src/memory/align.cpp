
#ifndef __UTILITY_MEMORY_ALIGN__
#define __UTILITY_MEMORY_ALIGN__

#include<utility/config/utility_config.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(memory)
    void* align(size_t _alignment, size_t _size, void*& _ptr, size_t& _space)
    {
      typedef unsigned char* _data_type;
      void* __res = nullptr;
      if(_size <= _space)
      {
        _data_type __tmp = static_cast<_data_type>(_ptr);
        _data_type __align_tmp = reinterpret_cast<_data_type>(
          (reinterpret_cast<size_t>(_ptr) + (_alignment - 1)) & (-_alignment)
        );
        size_t __len = static_cast<size_t>(__align_tmp - __tmp);
        if(__len <= _space - _size)
        {
          _ptr = __res = __align_tmp;
          _space -= __len;
        }
      }

      return __res;
    }
  __utility_interspace_end(memory)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_MEMORY_ALIGN__
