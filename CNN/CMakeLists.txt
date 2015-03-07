file(GLOB CNN_src src/*.cpp)
file(GLOB CNN_h include/*.h)

add_library (CNN 
  ${CNN_h}
  ${CNN_src})

install (TARGETS CNN DESTINATION bin)
install (FILES include/CNN.h DESTINATION include)

add_executable(test_CNN test/test_CNN.cpp ${gtest_SOURCE_DIR}/include)
target_link_libraries(test_CNN CNN gtest)
add_test(NAME test_CNN COMMAND test_CNN)
