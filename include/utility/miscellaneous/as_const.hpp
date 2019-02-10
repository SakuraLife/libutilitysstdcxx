
#ifndef __UTILITY_MISCELLANEOUS_AS_CONST__
#define __UTILITY_MISCELLANEOUS_AS_CONST__

#include<utility/config/utility_config.hpp>
#include<utility/trait/type/transform/add_cv.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(miscellaneous)
    /**
     * \brief Forms value to const type
     *
     * Forms lvalue reference to const type of \a _val
     *
     * \param _val lvalue reference to const
     * \return \a _val (const reference)
     */
    template<typename _T>
    __UTILITY_CPP14_CONSTEXPR__
    trait::type::transform::add_cv_t<_T> as_const(_T& _val) noexcept
    { return _val;}

    template<typename _T>
    void as_const(const _T&&) = delete;
  __utility_interspace_end(miscellaneous)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_MISCELLANEOUS_AS_CONST__
