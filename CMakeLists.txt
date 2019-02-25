
cmake_minimum_required(VERSION 3.11)

set(CMAKE_MODULE_PATH
  "${PROJECT_SOURCE_DIR}/cmake"
  ${CMAKE_MODULE_PATH}
)

include(ComplieOption)
include(SysInfo)

add_compile_flags_if_supported(-Wall -Warray-bounds -Wcast-align -Wfloat-equal -Wfloat-conversion -Winit-self -Winline -Wlogical-op -Wunused -Wmain -Wreturn-type -Wshadow -Wtype-limits -Wsign-conversion)
add_compile_flags_if_supported(-O3)
add_compile_flags_if_supported(-std=c++11)
add_compile_flags_if_supported(-fPIC)

string(REGEX REPLACE ";" " " CXX_COMPILE_OPTIONS "${CXX_COMPILE_FLAGS}")
set(CMAKE_CXX_IMPLICIT_LINK_LIBRARIES "")
set(CMAKE_CXX_IMPLICIT_LINK_DIRECTORIES "")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_COMPILE_OPTIONS}")

cmake_host_system_information(RESULT CXX_BITS QUERY IS_64BIT)

type_size()
check_endian()

# set(CXX_CHAR_BITS ${CXX_CHAR})
# message("short:       " ${CXX_SHORT})
# message("int:         " ${CXX_INT})
# message("long:        " ${CXX_LONG})
# message("long long:   " ${CXX_LLONG})
# message("float:       " ${CXX_FLOAT})
# message("double:      " ${CXX_DOUBLE})
# message("long double: " ${CXX_LDOUBE})
# message("void*:       " ${CXX_PTR})

option(CXX_DEV, "enable dev build" OFF)

configure_file(generate/utility_preconfig.hpp.in include/utility/config/utility_preconfig.hpp @ONLY)

include_directories("./include")

file(GLOB_RECURSE SSTD_HEADERS ${PROJECT_SOURCE_DIR}/include/*)

aux_source_directory("./src/builtin" SSTD_BUILTIN_SRC)

add_library(sstdabi_object OBJECT ${SSTD_BUILTIN_SRC})
set(sstdabi_static_object $<TARGET_OBJECTS:sstdabi_object>)
set(sstdabi_shared_object $<TARGET_OBJECTS:sstdabi_object>)


add_library(sstdabi_shared SHARED ${sstdabi_shared_object})
set_target_properties(sstdabi_shared PROPERTIES LINKER_LANGUAGE C)
set_target_properties(sstdabi_shared PROPERTIES OUTPUT_NAME sstdabi)
set_target_properties(sstdabi_shared PROPERTIES LINK_FLAGS "-fno-rtti -fno-exceptions")

add_library(sstdabi_static STATIC ${sstdabi_static_object})
set_target_properties(sstdabi_static PROPERTIES LINKER_LANGUAGE C)
set_target_properties(sstdabi_static PROPERTIES OUTPUT_NAME sstdabi)
set_target_properties(sstdabi_static PROPERTIES LINK_FLAGS "-fno-rtti -fno-exceptions")

add_library(sstdc++_shared SHARED ${SSTD_HEADERS})
set_target_properties(sstdc++_shared PROPERTIES LINKER_LANGUAGE C)
set_target_properties(sstdc++_shared PROPERTIES OUTPUT_NAME sstdc++)

add_library(sstdc++_static STATIC ${SSTD_HEADERS})
set_target_properties(sstdc++_static PROPERTIES LINKER_LANGUAGE C)
set_target_properties(sstdc++_static PROPERTIES OUTPUT_NAME sstdc++)
