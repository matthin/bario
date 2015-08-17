set(testSourceFiles
  ${CMAKE_CURRENT_SOURCE_DIR}/main.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/Commit.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/Contrast.cc
)

include_directories(.)

add_executable(barioTest ${testSourceFiles})
target_link_libraries(
  barioTest
  bario
)

