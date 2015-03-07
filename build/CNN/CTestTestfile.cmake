# CMake generated Testfile for 
# Source directory: /Users/ndr/Documents/mycode/EasyCNNApp/CNN
# Build directory: /Users/ndr/Documents/mycode/EasyCNNApp/build/CNN
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(test_CNN "/Users/ndr/Documents/mycode/EasyCNNApp/build/CNN/Debug/test_CNN")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(test_CNN "/Users/ndr/Documents/mycode/EasyCNNApp/build/CNN/Release/test_CNN")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(test_CNN "/Users/ndr/Documents/mycode/EasyCNNApp/build/CNN/MinSizeRel/test_CNN")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(test_CNN "/Users/ndr/Documents/mycode/EasyCNNApp/build/CNN/RelWithDebInfo/test_CNN")
else()
  add_test(test_CNN NOT_AVAILABLE)
endif()
