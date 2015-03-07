cmake_minimum_required (VERSION 2.8)
project (EasyCNN)


enable_testing()
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} -VV)

add_subdirectory (3rdparty/gtest-1.7.0)
include_directories(${gtest_SOURCE_DIR}/include)

include_directories(CNN/include)
add_subdirectory (CNN)

add_subdirectory (EasyCNNApp)
