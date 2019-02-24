
#ifndef ___UTILITY__VISIBILITY__CONFIG___
#define ___UTILITY__VISIBILITY__CONFIG___

#if defined(_WIN32)
#define _WIN32

#if defined(UTILITY_DISABLE_VIS)
# define __UTILITY_DLL_VIS
# define __UTILITY_EXTERN_TEMPLATE_TYPE_VIS
# define __UTILITY_CLASS_TEMPLATE_INST_VIS
# define __UTILITY_OVERRIDABLE_FUNC_VIS
# define __UTILITY_EXPORTED_FROM_ABI
#elif defined(UTILITY_BUILDING_LIBRARY)
# define __UTILITY_DLL_VIS __declspec(dllexport)
# define __UTILITY_EXTERN_TEMPLATE_TYPE_VIS
# define __UTILITY_CLASS_TEMPLATE_INST_VIS __UTILITY_DLL_VIS
# define __UTILITY_OVERRIDABLE_FUNC_VIS __UTILITY_DLL_VIS
# define __UTILITY_EXPORTED_FROM_ABI __declspec(dllexport)
#else
# define __UTILITY_DLL_VIS __declspec(dllimport)
# define __UTILITY_EXTERN_TEMPLATE_TYPE_VIS __UTILITY_DLL_VIS
# define __UTILITY_CLASS_TEMPLATE_INST_VIS
# define __UTILITY_OVERRIDABLE_FUNC_VIS
# define __UTILITY_EXPORTED_FROM_ABI __declspec(dllimport)
#endif

#define __UTILITY_TYPE_VIS            __UTILITY_DLL_VIS
#define __UTILITY_FUNC_VIS            __UTILITY_DLL_VIS
#define __UTILITY_EXCEPTION_ABI       __UTILITY_DLL_VIS
#define __UTILITY_TEMPLATE_VIS_HIDDEN
#define __UTILITY_METHOD_TEMPLATE_IMPLICIT_INST_VIS
#define __UTILITY_TEMPLATE_VIS
#define __UTILITY_ENUM_VIS
#define __UTILITY_ABI                 __UTILITY_DLL_VIS

#endif // _WIN32

#if !defined(__UTILITY_VIS_HIDDEN)
# if !defined(UTILITY_DISABLE_VIS)
# define __UTILITY_VIS_HIDDEN __attribute__ ((__visibility__("hidden")))
# else
# define __UTILITY_VIS_HIDDEN
# endif // UTILITY_DISABLE_VIS
#endif // __UTILITY_VIS_HIDDEN

#ifndef __UTILITY_METHOD_TEMPLATE_IMPLICIT_INST_VIS
# if !defined(UTILITY_DISABLE_VIS)
# define __UTILITY_METHOD_TEMPLATE_IMPLICIT_INST_VIS \
  inline __UTILITY_VIS_HIDDEN
# else
# define __UTILITY_METHOD_TEMPLATE_IMPLICIT_INST_VIS
# endif
#endif


#ifndef __UTILITY_FUNC_VIS
# if !defined(UTILITY_DISABLE_VIS)
# define __UTILITY_FUNC_VIS __attribute__ ((__visibility__("default")))
# else
# define __UTILITY_FUNC_VIS
# endif
#endif

#ifndef __UTILITY_TYPE_VIS
# if !defined(UTILITY_DISABLE_VIS)
# define __UTILITY_TYPE_VIS __attribute__ ((__visibility__("default")))
# else
# define __UTILITY_TYPE_VIS
# endif
#endif

#ifndef __UTILITY_TEMPLATE_VIS
# if !defined(UTILITY_DISABLE_VIS)
#    if __has_attribute(__type_visibility__)
#    define __UTILITY_TEMPLATE_VIS __attribute__ ((__type_visibility__("default")))
#    else
#    define __UTILITY_TEMPLATE_VIS __attribute__ ((__visibility__("default")))
#    endif
# else
# define __UTILITY_TEMPLATE_VIS
# endif
#endif

#ifndef __UTILITY_OVERRIDABLE_FUNC_VIS
#define __UTILITY_OVERRIDABLE_FUNC_VIS __UTILITY_FUNC_VIS
#endif

#ifndef __UTILITY_EXCEPTION_ABI
# if !defined(UTILITY_DISABLE_VIS)
# define __UTILITY_EXCEPTION_ABI __attribute__ ((__visibility__("default")))
# else
# define __UTILITY_EXCEPTION_ABI
# endif
#endif

#ifndef __UTILITY_ENUM_VIS
# if !defined(UTILITY_DISABLE_VIS) && __has_attribute(__type_visibility__)
# define __UTILITY_ENUM_VIS __attribute__ ((__type_visibility__("default")))
# else
# define __UTILITY_ENUM_VIS
# endif
#endif

#ifndef __UTILITY_EXTERN_TEMPLATE_TYPE_VIS
# if !defined(UTILITY_DISABLE_VIS) && __has_attribute(__type_visibility__)
# define __UTILITY_EXTERN_TEMPLATE_TYPE_VIS __attribute__ ((__visibility__("default")))
# else
# define __UTILITY_EXTERN_TEMPLATE_TYPE_VIS
# endif
#endif

#ifndef __UTILITY_CLASS_TEMPLATE_INST_VIS
#define __UTILITY_CLASS_TEMPLATE_INST_VIS
#endif

#if __has_attribute(internal_linkage)
# define __UTILITY_INTERNAL_LINKAGE __attribute__ ((internal_linkage))
#else
# define __UTILITY_INTERNAL_LINKAGE __UTILITY_ALWAYS_INLINE
#endif


#ifndef __UTILITY_EXPORTED_FROM_ABI
# if !defined(UTILITY_DISABLE_VIS)
# define __UTILITY_EXPORTED_FROM_ABI __attribute__((__visibility__("default")))
# else
# define __UTILITY_EXPORTED_FROM_ABI
# endif
#endif


#if __has_attribute(exclude_from_explicit_instantiation)
# define __UTILITY_EXCLUDE_FROM_EXPLICIT_INST __attribute__ ((__exclude_from_explicit_instantiation__))
#else
   // Try to approximate the effect of exclude_from_explicit_instantiation
   // (which is that entities are not assumed to be provided by explicit
   // template instantitations in the dylib) by always inlining those entities.
# define __UTILITY_EXCLUDE_FROM_EXPLICIT_INST __UTILITY_ALWAYS_INLINE
#endif

#ifndef __UTILITY_HIDE_FROM_ABI
# if defined(UTILITY_HIDE_FROM_ALL)
# define __UTILITY_HIDE_FROM_ABI __UTILITY_VIS_HIDDEN __UTILITY_INTERNAL_LINKAGE
# else
# define __UTILITY_HIDE_FROM_ABI __UTILITY_VIS_HIDDEN __UTILITY_EXCLUDE_FROM_EXPLICIT_INST
# endif
#endif

#ifndef __UTILITY_ABI
#define __UTILITY_ABI extern
#else
#define __UTILITY_ABI extern
#endif

#define __UTILITY_INLINE_VISIBILITY __UTILITY_HIDE_FROM_ABI

#endif // ! ___UTILITY__VISIBILITY__CONFIG___
