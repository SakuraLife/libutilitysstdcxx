
cmake_minimum_required(VERSION 3.11)

set(CMAKE_MODULE_PATH
  "${PROJECT_SOURCE_DIR}/cmake"
  ${CMAKE_MODULE_PATH}
)

include(ComplieOption)
include(SysInfo)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)

# LINK_DIRECTORIES(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

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

set(SSTD_VERSION_RELEASE 0)
set(SSTD_VERSION_INTERFACE 4)
set(SSTD_VERSION_INCREMENTAL 0)
set(SSTD_VERSION ${SSTD_VERSION_RELEASE}.${SSTD_VERSION_INTERFACE}.${SSTD_VERSION_INCREMENTAL})

set(SSTDBUILTIN_VERSION_RELEASE 1)
set(SSTDBUILTIN_VERSION_INTERFACE 0)
set(SSTDBUILTIN_VERSION_INCREMENTAL 0)
set(SSTDBUILTIN_VERSION ${SSTDBUILTIN_VERSION_RELEASE}.${SSTDBUILTIN_VERSION_INTERFACE}.${SSTDBUILTIN_VERSION_INCREMENTAL})

set(SSTD_LIBRAY "")
add_link_flags_if_have(SSTD_LIBRAY c remove)
add_link_flags_if_have(SSTD_LIBRAY m fmod)

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

file(GLOB_RECURSE SSTD_SRC ${PROJECT_SOURCE_DIR}/include/*)
file(GLOB_RECURSE SSTD_SRC_memory ${PROJECT_SOURCE_DIR}/src/memory/*)

list(APPEND SSTD_SRC ${SSTD_SRC_memory})
aux_source_directory("${PROJECT_SOURCE_DIR}/src/builtin" SSTD_BUILTIN_SRC)

add_library(sstdabi_object OBJECT ${SSTD_BUILTIN_SRC})
set(sstdabi_static_object $<TARGET_OBJECTS:sstdabi_object>)
set(sstdabi_shared_object $<TARGET_OBJECTS:sstdabi_object>)

add_library(sstdc++_object OBJECT ${SSTD_SRC})
set(sstdc++_static_object $<TARGET_OBJECTS:sstdc++_object>)
set(sstdc++_shared_object $<TARGET_OBJECTS:sstdc++_object>)

add_library(sstdabi_shared SHARED ${sstdabi_shared_object})
set_target_properties(
  sstdabi_shared PROPERTIES
  LINKER_LANGUAGE C
  OUTPUT_NAME sstdabi
  SOVERSION ${SSTDBUILTIN_VERSION_RELEASE}
  VERSION ${SSTDBUILTIN_VERSION}
  LINK_FLAGS "-fno-rtti -fno-exceptions"
)

add_library(sstdabi_static STATIC ${sstdabi_static_object})
set_target_properties(
  sstdabi_static PROPERTIES
  LINKER_LANGUAGE C
  OUTPUT_NAME sstdabi
  LINK_FLAGS "-fno-rtti -fno-exceptions"
)

add_library(sstdc++_shared SHARED ${sstdc++_shared_object})
set_target_properties(sstdc++_shared PROPERTIES LINKER_LANGUAGE C)
set_target_properties(
  sstdc++_shared PROPERTIES
  LINKER_LANGUAGE C
  SOVERSION ${SSTD_VERSION_RELEASE}
  VERSION ${SSTD_VERSION}
  OUTPUT_NAME sstdc++
)
# set_target_properties(sstdc++_shared PROPERTIES LINK_FLAGS "")
target_link_libraries(sstdc++_shared PRIVATE sstdabi_shared ${SSTD_LIBRAY})

add_library(sstdc++_static STATIC ${sstdc++_static_object})
set_target_properties(
  sstdc++_static PROPERTIES
  LINKER_LANGUAGE C
  OUTPUT_NAME sstdc++
)
target_link_libraries(sstdc++_static PRIVATE sstdabi_static ${SSTD_LIBRAY})
