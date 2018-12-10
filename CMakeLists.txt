
cmake_minimum_required(VERSION 3.11)

set(CMAKE_MODULE_PATH
  "./cmake"
  ${CMAKE_MODULE_PATH}
)

include(ComplieOption)
include(SysInfo)

add_compile_flags_if_supported(-Wall -Warray-bounds -Wcast-align -Wfloat-equal -Wfloat-conversion -Winit-self -Winline -Wlogical-op -Wunused -Wmain -Wreturn-type -Wshadow -Wtype-limits -Wsign-conversion)
add_compile_flags_if_supported(-O3)
add_compile_flags_if_supported(-std=c++11)

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

configure_file(generate/utility_preconfig.hpp.in include/utility/config/utility_preconfig.hpp @ONLY)

include_directories("./include")

aux_source_directory(./src/charS LIB_SRC)
aux_source_directory(./src/ctype LIB_SRC)
aux_source_directory(./src/errno LIB_SRC)

add_library(sstdc++_shared SHARED ${LIB_SRC})
add_library(sstdc++_static STATIC ${LIB_SRC})

set_target_properties(sstdc++_shared PROPERTIES OUTPUT_NAME sstdc++)
set_target_properties(sstdc++_shared PROPERTIES LINK_FLAGS "-nodefaultlibs -fno-rtti -fno-exceptions")

set_target_properties(sstdc++_static PROPERTIES OUTPUT_NAME sstdc++)
set_target_properties(sstdc++_static PROPERTIES LINK_FLAGS "-nodefaultlibs -fno-rtti -fno-exceptions")
