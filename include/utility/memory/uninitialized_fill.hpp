
#ifndef __UTILITY_MEMORY_UNINITIALIZED_FILL__
#define __UTILITY_MEMORY_UNINITIALIZED_FILL__

#include<utility/config/utility_config.hpp>
#include<utility/memory/addressof.hpp>
#include<utility/iterator/iterator_traits.hpp>
#include<utility/sstd/new.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(memory)
    /*!
    * \brief Fill block of memory
    *
    * Constructs all the elements in the range [\a _first,\a _last)
    * initializing them to a value of \a _val.<br/>
    * \b uninitialized_fill constructs the objects in-place,
    * instead of just copying the value to them. This allows to obtain
    * fully constructed copies into a range of uninitialized memory
    *
    * \param _first,_last Forward iterators to the initial and final positions
    *         in an uninitialized sequence. The range affected is
    *         [\a _first,\a _last), which contains all the elements
    *         between \a _first and \a _last, including the element
    *         pointed by \a _first but not the element pointed by \a _last.
    * \param _val Value to be used to fill the range.
    * \return none
    * \attention If an exception is thrown during the initialization,
    *         the function has no effects.
    * \see memory::uninitialized_fill_n
    */
    template<typename _ForwardIterator, typename _T>
    void
    uninitialized_fill(_ForwardIterator _first, _ForwardIterator _last, const _T& _val)
    {
      typedef typename
        iterator::iterator_traits<_ForwardIterator>::value_type
        __value_type;
      __UTILITY_TRY_DEFINE(_ForwardIterator, __epos, _first);
      __UTILITY_TRY_BEGIN
        for(; _first != _last; ++_first)
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
    }
  __utility_interspace_end(memory)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_MEMORY_UNINITIALIZED_FILL__
