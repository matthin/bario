cmake_minimum_required(VERSION 2.8)
project(bario CXX)

add_subdirectory(src)
include_directories(include/bario)
include_directories(opt/catch/include)

add_library(
  bario
  STATIC
  ${barioSourceFiles}
)

target_link_libraries(
  bario
  crypto
)

ADD_DEFINITIONS(-std=c++11)
SET(CMAKE_EXE_LINKER_FLAGS "-pthread")

add_subdirectory(test)
enable_testing()
add_test(NAME barioTest COMMAND barioTest)

