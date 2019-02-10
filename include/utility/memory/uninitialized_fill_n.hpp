
#ifndef __UTILITY_MEMORY_UNINITIALIZED_FILL_N__
#define __UTILITY_MEMORY_UNINITIALIZED_FILL_N__

#include<utility/config/utility_config.hpp>
#include<utility/memory/addressof.hpp>
#include<utility/iterator/iterator_traits.hpp>
#include<utility/sstd/new.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(memory)
  {
    /*!
    * \brief Fill block of memory
    *
    * Constructs n elements in the array pointed by \a _first,
    * initializing them to a value of \a _val.<br/>
    * \b uninitialized_fill_n constructs the objects in-place,
    * instead of just copying the value to them.
    * This allows to obtain fully constructed copies into
    * a range of uninitialized memory.
    *
    * \param _first Forward iterator to the initial position
    *         in an uninitialized sequence of at least n elements.
    * \param _size Number of elements to initialize
    * \param _val Value to be used to fill the range
    * \return An iterator to the last element of the destination sequence
    *         where elements have been initialized.
    * \attention If an exception is thrown during the initialization,
    *         the function has no effects.
    * \see memory::uninitialized_fill
    */
    template<typename _ForwardIterator, typename _Size, typename _T>
    _ForwardIterator
    uninitialized_fill_n(_ForwardIterator _first, _Size _size, const _T& _val)
    {
      typedef typename
        iterator::iterator_traits<_ForwardIterator>::value_type
        __value_type;
      __UTILITY_TRY_DEFINE(_ForwardIterator, __epos, _first);
      __UTILITY_TRY_BEGIN
        for(; _size > 0; ++_first, --_size)
        {
          ::new (static_cast<void*>(memory::addressof(*_first)))
          __value_type(_val);
        }
      __UTILITY_TRY_END
      __UTILITY_CATCH(...)
      __UTILITY_CATCH_UNWIND(
        for(; __epos != _first; ++__epos)
        { __epos->~__value_type();}
      )
      return _first;
    }
  }
__utility_globalspace_end(utility)

#endif // ! __UTILITY_MEMORY_UNINITIALIZED_FILL__
