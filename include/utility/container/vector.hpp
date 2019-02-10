
#ifndef __UTILITY_CONTAINER_VECTOR__
#define __UTILITY_CONTAINER_VECTOR__

/**
 * \file vector.hpp
 * \author Inochi Amaoto
 *
 */

#include<utility/config/utility_config.hpp>
#include<utility/container/container_helper.hpp>

#include<utility/algorithm/move.hpp>
#include<utility/algorithm/forward.hpp>
#include<utility/algorithm/swap.hpp>
#include<utility/algorithm/possible_swap.hpp>
#include<utility/algorithm/equal.hpp>
#include<utility/algorithm/lexicographical_compare.hpp>

#include<utility/container/compressed_pair.hpp>

#include<utility/memory/allocator.hpp>
#include<utility/memory/allocator_traits.hpp>
#include<utility/memory/unique_ptr.hpp>
#include<utility/memory/uninitialized_copy.hpp>
#include<utility/memory/uninitialized_fill_n.hpp>
#include<utility/memory/uninitialized_move.hpp>
#include<utility/memory/uninitialized_possible_move.hpp>
#include<utility/memory/basic_deallocator.hpp>

#include<utility/trait/opt/__control__.hpp>
#include<utility/trait/type/features/is_nothrow_swappable.hpp>
#include<utility/trait/type/features/is_nothrow_possible_swappable.hpp>

#include<utility/iterator/raw_pointer_iterator.hpp>
#include<utility/iterator/distance.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(container)
  {
    namespace __detail
    {
      using trait::__opt__::__eq__;
      using trait::__opt__::__if__;
      using trait::__opt__::__bool__;
      using trait::__opt__::__true__;
      using trait::__opt__::__false__;
      using trait::type::features::is_nothrow_swappable;
      using trait::type::features::is_nothrow_possible_swappable;

    }

    template<
      typename _T,
      typename _Alloc = memory::allocator<_T>
    >
    class vector
    {
      public:
        typedef _T                    value_type;
        typedef _Alloc                allocator_type;
        typedef size_t                size_type;
        typedef ptrdiff_t             difference_type;
        typedef value_type&           reference;
        typedef const value_type&     const_reference;

      public:
        typedef memory::allocator_traits<allocator_type>
          allocator_traits_type;

      public:
        typedef typename allocator_traits_type::pointer pointer;
        typedef typename allocator_traits_type::const_pointer const_pointer;

      public:
        typedef helper::raw_pointer_iterator<_T>        iterator;
        typedef helper::raw_pointer_iterator<const _T>  const_iterator;
        typedef helper::reverse_iterator<iterator>
          reverse_iterator;
        typedef helper::reverse_iterator<const_iterator>
          const_reverse_iterator;

      public: // assert
        static_assert(
          __detail::__eq__<
            value_type, typename allocator_type::value_type
          >::value,
          "the allocator's value type must be the same as value type"
        );

      private:
        typedef compressed_pair<pointer, allocator_type> __mis_type;

      private:
        pointer     __begin;
        pointer     __end;
        __mis_type  __mis;

      private:
        explicit vector(allocator_type&& _alloc) noexcept:
          __begin{nullptr}, __end{nullptr},
          __mis{nullptr, algorithm::move(_alloc)}
        { }

      public:
        vector() noexcept(noexcept(allocator_type{})):
          vector{allocator_type{}}
        { }
        explicit vector(const allocator_type& _alloc) noexcept:
          __begin{nullptr}, __end{nullptr}, __mis{nullptr, _alloc}
        { }
        explicit vector(
          size_type _count, const value_type& _val,
          const allocator_type& _alloc = allocator_type{}
        ): vector{_alloc}
        { assign(_count, _val);}
        explicit vector(
          size_type _count,
          const allocator_type& _alloc = allocator_type{}
        ): vector{_alloc}
        { __init_n(_count);}
        template<
          typename _Inputiterator,
          typename __detail::__if__<
            is_iterator<_Inputiterator>::value,
            bool
          >::type = true
        >
        vector(
          _Inputiterator _first, _Inputiterator _last,
          const allocator_type& _alloc = allocator_type{}
        ): vector{_alloc}
        { assign(_first, _last);}

        vector(const vector& _other): vector{_other.get_allocator()}
        { assign(_other.begin(), _other.end());}
        vector(const vector& _other, const allocator_type& _alloc):
          vector{_alloc}
        { assign(_other.begin(), _other.end());}
        vector(vector&& _other) noexcept:
          vector{algorithm::move(_other.__mis.second())}
        {
          __begin = _other.__begin;
          __end = _other.__end;
          __mis.first() = _other.__mis.first();
          _other.__begin = _other.__end = _other.__mis.first() = nullptr;
        }
        vector(vector&& _other, const allocator_type& _alloc): vector{_alloc}
        {
          using helper::move_iterator;
          if(__mis.second() == _other.__mis.second())
          {
            __begin = _other.__begin;
            __end = _other.__end;
            __mis.first() = _other.__mis.first();
            _other.__begin = _other.__end = _other.__mis.first() = nullptr;
          }
          else
          {
            assign(
              move_iterator<iterator>{_other.begin()},
              move_iterator<iterator>{_other.end()}
            );
          }
        }

        vector(
          initializer_list<value_type> _init,
          const allocator_type& _alloc = allocator_type()
        ): vector{_alloc}
        { assign(_init.begin(), _init.end());}

      public:
        ~vector()
        { give_up();}

      public:
        vector& operator=(const vector& _other)
        {
          typedef __detail::__bool__<
            allocator_traits_type::propagate_on_container_copy_assignment::value
          > __identification_t;
          if(this != &_other)
          {
            allocator_copy(_other.__mis.second(), __identification_t{});
            assign(_other.begin(), _other.end());
          }
          return *this;
        }
        vector& operator=(vector&& _other) noexcept(
          allocator_traits_type::propagate_on_container_move_assignment::value ||
          allocator_traits_type::is_always_equal::value
        )
        {
          typedef __detail::__bool__<
            allocator_traits_type::propagate_on_container_move_assignment::value
          > __identification_t;
          if(this != &_other)
          {
            if(__mis.second() != _other.__mis.second())
            { assign(_other.begin(), _other.end());}
            else
            {
              give_up();
              allocator_move(_other.__mis.second(), __identification_t{});
              __begin = _other.__begin;
              __end = _other.__end;
              __mis.first() = _other.__mis.first();
              _other.__begin = _other.__end = _other.__mis.first() = nullptr;
            }
          }
          return *this;
        }
        vector& operator=(initializer_list<value_type> _init)
        {
          assign(_init.begin(), _init.end());
          return *this;
        }

      public:
        void assign(size_type _count, const value_type& _val)
        {
          using memory::uninitialized_fill_n;

          clear();
          __check(_count);
          uninitialized_fill_n(__begin, _count, _val);

          __end = __begin + _count;
        }
        template<
          typename _Inputiterator,
          typename __detail::__if__<
            is_iterator<_Inputiterator>::value,
            bool
          >::type = true
        >
        void assign(_Inputiterator _first, _Inputiterator _last)
        {
          using helper::distance;
          using memory::uninitialized_copy;

          size_type __count = distance(_first, _last);
          this->clear();
          __check(__count);
          uninitialized_copy(_first, _last, __begin);

          __end = __begin + __count;
        }
        void assign(initializer_list<value_type> _init)
        { assign(_init.begin(), _init.end());}

      public:
        allocator_type get_allocator() const
        { return __mis.second();}

      public:
        inline reference at(size_type _pos);
        inline const_reference at(size_type _pos) const;
        inline reference operator[](size_type _pos)
        { return __begin[_pos];}
        inline const_reference operator[](size_type _pos) const
        { return __begin[_pos];}

      public:
        inline reference front() noexcept
        { return *__begin;}
        inline const_reference front() const noexcept
        { return *__begin;}
        inline reference back() noexcept
        { return *(__end - 1);}
        inline const_reference back() const noexcept
        { return *(__end - 1);}
        inline pointer data() noexcept
        { return __begin;}
        inline const_pointer data() const noexcept
        { return __begin;}

      public:
        inline bool empty() const noexcept
        { return __begin == __end;}
        inline size_type size() const noexcept
        { return __end - __begin;}
        inline size_type capacity() const noexcept
        { return __mis.first() - __begin;}

      public:
        inline iterator begin() noexcept
        { return iterator{__begin};}
        inline const_iterator begin() const noexcept
        { return const_iterator{__begin};}
        inline const_iterator cbegin() const noexcept
        { return const_iterator{__begin};}
        inline iterator end() noexcept
        { return iterator{__end};}
        inline const_iterator end() const noexcept
        { return const_iterator{__end};}
        inline const_iterator cend() const noexcept
        { return const_iterator{__end};}
        inline reverse_iterator rbegin() noexcept
        { return reverse_iterator{end()};}
        inline const_reverse_iterator rbegin() const noexcept
        { return const_reverse_iterator{end()};}
        inline const_reverse_iterator crbegin() const noexcept
        { return const_reverse_iterator{end()};}
        inline reverse_iterator rend() noexcept
        { return reverse_iterator{begin()};}
        inline const_reverse_iterator rend() const noexcept
        { return const_reverse_iterator{begin()};}
        inline const_reverse_iterator crend() const noexcept
        { return const_reverse_iterator{begin()};}

      public:
        void push_back(const value_type& _val)
        { __insert(__end - __begin, 1, _val);}
        void push_back(value_type&& _val)
        {
          using algorithm::move;
          __insert(__end - __begin, move(_val));
        }
        template<typename... _Args>
        iterator emplace(const_iterator _pos, _Args&&... _args)
        {
          using algorithm::forward;
          return __emplace(_pos.__ptr - __begin, forward<_Args>(_args)...);
        }
        template<typename... _Args>
        reference emplace_back(_Args&&... _args)
        {
          using algorithm::forward;
          return *__emplace(__end - __begin, forward<_Args>(_args)...);
        }

      public:
        void pop_back()
        { allocator_traits_type::destroy(__mis.second(), --__end);}

      public:
        iterator insert(const_iterator _pos, const value_type& _val)
        { return __insert(_pos.__ptr - __begin, 1, _val);}
        iterator insert(const_iterator _pos, value_type&& _val)
        {
          using algorithm::move;
          return __insert(_pos.__ptr - __begin, move(_val));
        }
        iterator insert(
          const_iterator _pos, size_type _count, const value_type& _val
        )
        { return __insert(_pos.__ptr - __begin, _count, _val);}
        template<
          typename _Inputiterator,
          typename __detail::__if__<
            is_iterator<_Inputiterator>::value,
            bool
          >::type = true
        >
        iterator insert(
          const_iterator _pos, _Inputiterator _first, _Inputiterator _last
        )
        { return __insert(_pos.__ptr - __begin, _first, _last);}
        iterator insert(
          const_iterator _pos, initializer_list<value_type> _init
        )
        { return __insert(_pos.__ptr - __begin, _init.begin(), _init.end());}

      public:
        iterator erase(const_iterator _pos)
        {
          using memory::uninitialized_move;

          pointer __tptr = const_cast<pointer>(_pos.__ptr);

          allocator_traits_type::destroy(__mis.second(), __tptr);
          uninitialized_move(__tptr+1, __end, __tptr);
          --__end;

          return iterator{__tptr};
        }
        iterator erase(const_iterator _first, const_iterator _last)
        {
          using memory::uninitialized_move;

          difference_type __count = _last.__ptr - _first.__ptr;

          pointer __tptr = const_cast<pointer>(_first.__ptr);
          for(difference_type __i = 0; __i < __count; ++__i)
          { allocator_traits_type::destroy(__mis.second(), __tptr + __i);}
          uninitialized_move(__tptr + __count, __end, __tptr);
          __end -= __count;

          return iterator{__tptr};
        }

      public:
        void clear() noexcept
        {
          for(pointer __ptr = __begin; __ptr != __end; ++__ptr)
          { allocator_traits_type::destroy(__mis.second(), __ptr);}
          __end = __begin;
        }
        void reserve(size_type _new)
        { reallocate(_new);}
        void shrink_to_fit()
        {
          size_type __size = size();
          if(__size != capacity())
          { reallocate(__size);}
        }
        void resize(size_type _count)
        {
          size_type __size = size();
          if(_count == __size)
          { return;}
          if(_count < capacity())
          {
            if(_count < __size)
            {
              erase(const_iterator{__begin + _count}, end());
              return;
            }
          }
          else
          { reallocate(_count << 1);}
          for(; __size != _count; ++__size)
          { this->emplace_back();}
        }
        void resize(size_type _count, const value_type& _val)
        {
          size_type __size = size();
          if(_count == __size)
          { return;}
          if(_count < capacity())
          {
            if(_count < __size)
            {
              erase(const_iterator{__begin + _count}, end());
              return;
            }
          }
          else
          { reallocate(_count << 1);}
          for(; __size != _count; ++__size)
          { this->emplace_back(_val);}
        }

      public:
        void swap(vector& _other) noexcept(
          allocator_traits_type::propagate_on_container_swap::value ||
          allocator_traits_type::is_always_equal::value
        )
        {
          using algorithm::swap;
          swap(__begin, _other.__begin);
          swap(__end,   _other.__end);
          swap(__mis,   _other.__mis);
        }
        void possible_swap(vector& _other) noexcept(
          allocator_traits_type::propagate_on_container_swap::value ||
          allocator_traits_type::is_always_equal::value
        )
        {
          using algorithm::swap;
          swap(__begin, _other.__begin);
          swap(__end,   _other.__end);
          swap(__mis,   _other.__mis);
        }

      private:
        iterator __insert(size_type _pos, value_type&& _val)
        {
          using memory::uninitialized_move_backward;
          using memory::uninitialized_move;
          __check(1);
          uninitialized_move_backward(__begin + _pos, __end, __end + 1);
          __UTILITY_TRY_BEGIN
            allocator_traits_type::construct(
              __mis.second(), __begin + _pos, _val
            );
          __UTILITY_TRY_END
          __UTILITY_CATCH(...)
          __UTILITY_CATCH_UNWIND();
          ++__end;

          return iterator{__begin + _pos};
        }
        iterator __insert(
          size_type _pos, size_type _count, const value_type& _val
        )
        {
          using memory::uninitialized_move_backward;
          using memory::uninitialized_move;
          __check(_count);
          uninitialized_move_backward(
            __begin + _pos, __end, __end + _count
          );
          pointer __ptr = __begin + _pos;
          __UTILITY_TRY_BEGIN
            for(size_type __i = 0; __i != _count; ++__ptr, ++__i)
            { allocator_traits_type::construct(__mis.second(), __ptr, _val);}
          __UTILITY_TRY_END
          __UTILITY_CATCH(...)
          __UTILITY_CATCH_UNWIND(
            for(pointer __eptr = __begin + _pos; __eptr != __ptr; ++__eptr)
            { allocator_traits_type::destroy(__mis.second(), __eptr);}
          );
          __end += _count;

          return iterator{__begin + _pos};
        }
        template<
          typename _Inputiterator,
          typename __detail::__if__<
            is_iterator<_Inputiterator>::value,
            bool
          >::type = true
        >
        iterator __insert(
          size_type _pos, _Inputiterator _first, _Inputiterator _last
        )
        {
          using helper::distance;
          using memory::uninitialized_move_backward;
          using memory::uninitialized_move;

          size_type __count = static_cast<size_type>(distance(_first, _last));

          __check(__count);
          uninitialized_move_backward(
            __begin + _pos, __end, __end + __count
          );
          pointer __ptr = __begin + _pos;
          __UTILITY_TRY_BEGIN
            for(; _first != _last; ++__ptr)
            {
              allocator_traits_type::construct(
                __mis.second(), __ptr, *_first++
              );
            }
          __UTILITY_TRY_END
          __UTILITY_CATCH(...)
          __UTILITY_CATCH_UNWIND(
            for(pointer __eptr = __begin + _pos; __eptr != __ptr; ++__eptr)
            { allocator_traits_type::destroy(__mis.second(), __eptr);}
          );
          __end += __count;

          return iterator{__begin + _pos};
        }
        template<typename... _Args>
        void __init_n(size_type _count)
        {
          using memory::uninitialized_move_backward;
          using memory::uninitialized_move;
          using algorithm::forward;

          reallocate(_count);
          pointer __ptr = __begin;
          __end += _count;
          __UTILITY_TRY_BEGIN
            for(; __ptr != __end; ++__ptr)
            { allocator_traits_type::construct(__mis.second(), __ptr);}
          __UTILITY_TRY_END
          __UTILITY_CATCH(...)
          __UTILITY_CATCH_UNWIND(
            for(pointer __eptr = __begin; __eptr != __ptr; ++__eptr)
            { allocator_traits_type::destroy(__mis.second(), __eptr);}
          );

        }
        template<typename... _Args>
        iterator __emplace(size_type _pos, _Args&&... _args)
        {
          using memory::uninitialized_move_backward;
          using memory::uninitialized_move;
          using algorithm::forward;

          __check(1);
          uninitialized_move_backward(__begin + _pos, __end, __end + 1);
          __UTILITY_TRY_BEGIN
            allocator_traits_type::construct(
              __mis.second(), __begin + _pos, forward<_Args>(_args)...
            );
          __UTILITY_TRY_END
          __UTILITY_CATCH(...)
          __UTILITY_CATCH_UNWIND();
          ++__end;

          return iterator{__begin + _pos};
        }

      private:
        void give_up()
        {
          if(__begin)
          {
            clear();
            allocator_traits_type::deallocate(
              __mis.second(), __begin, capacity()
            );
            // not need
            // __begin = __end = __mis.first() = nullptr;
          }
        }
        void __check(size_type _need)
        {
          pointer __cap = __mis.first();
          size_type __reserve = __cap - __end;
          if(__reserve < _need)
          {
            size_type __size = __cap - __begin;
            size_type __new = __size > _need ? __size: _need;
            __new <<= 1;
            reallocate(__new);
          }
        }
        void reallocate(size_type _need)
        {
          using memory::unique_ptr;
          using memory::basic_deallocator;
          using memory::uninitialized_move;

          size_type __size = size();

          unique_ptr<pointer, basic_deallocator<allocator_type>> __con{
            allocator_traits_type::allocate(__mis.second(), _need),
            basic_deallocator<allocator_type>{__mis.second(), _need}
          };

          uninitialized_move(__begin, __end, __con.get());
          allocator_traits_type::deallocate(
            __mis.second(), __begin, capacity()
          );

          __begin = __con.release();
          __end = __begin + __size;
          __mis.first() = __begin + _need;

          return;
        }

      private:
        inline void allocator_copy(
          const allocator_type& _alloc, __detail::__false__
        )
        { }
        inline void allocator_copy(
          const allocator_type& _alloc, __detail::__true__
        )
        {
          if(__mis.second() != _alloc)
          {
            clear();
            allocator_traits_type::deallocate(
              __mis.second(), __begin, capacity()
            );
            __begin = __end = __mis.first() = nullptr;
            __mis.second = _alloc;
          }
        }
        inline void allocator_move(
          const allocator_type& _alloc, __detail::__false__
        )
        { }
        inline void allocator_move(
          allocator_type& _alloc, __detail::__true__
        )
        {
          using algorithm::move;
          __mis.second() = move(_alloc);
        }
    };

    template<typename _T, typename _Alloc>
    inline bool operator==(
      const vector<_T, _Alloc>& _x, const vector<_T, _Alloc>& _y
    )
    {
      return _x.size() == _y.size() &&
        algorithm::equal(_x.begin(), _x.end(), _y.begin());
    }
    template<typename _T, typename _Alloc>
    inline bool operator!=(
      const vector<_T, _Alloc>& _x, const vector<_T, _Alloc>& _y
    )
    { return !(_x == _y);}
    template<typename _T, typename _Alloc>
    inline bool operator<(
      const vector<_T, _Alloc>& _x, const vector<_T, _Alloc>& _y
    )
    {
      return algorithm::lexicographical_compare(
        _x.begin(), _x.end(), _y.begin(), _y.end()
      );
    }
    template<typename _T, typename _Alloc>
    inline bool operator>(
      const vector<_T, _Alloc>& _x, const vector<_T, _Alloc>& _y
    )
    { return _y < _x;}
    template<typename _T, typename _Alloc>
    inline bool operator<=(
      const vector<_T, _Alloc>& _x, const vector<_T, _Alloc>& _y
    )
    { return !(_y < _x);}
    template<typename _T, typename _Alloc>
    inline bool operator>=(
      const vector<_T, _Alloc>& _x, const vector<_T, _Alloc>& _y
    )
    { return !(_x < _y);}

  }

   __utility_interspace_start(algorithm)
  {
    template<typename _T, typename _Alloc>
    inline void swap(
      container::vector<_T, _Alloc>& _x,
      container::vector<_T, _Alloc>& _y
    ) noexcept(noexcept(_x.swap(_y)))
    { _x.swap(_y);}
    template<typename _T, typename _Alloc>
    inline void possible_swap(
      container::vector<_T, _Alloc>& _x,
      container::vector<_T, _Alloc>& _y
    ) noexcept(noexcept(_x.possible_swap(_y)))
    { _x.possible_swap(_y);}
  }
__utility_globalspace_end(utility)

#endif // ! __UTILITY_CONTAINER_VECTOR__
