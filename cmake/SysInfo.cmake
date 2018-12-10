
include(TestBigEndian)

macro(check_endian)
test_big_endian(CXX_BIG_ENDIAN)
if(${CXX_BIG_ENDIAN})
  set(CXX_LITTLE_ENDIAN "0")
else(${CXX_BIG_ENDIAN})
  set(CXX_LITTLE_ENDIAN "1")
endif(${CXX_BIG_ENDIAN})
endmacro()
