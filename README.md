# EasyCNN

This is a an example of a library and an application which mock object recognition using convolutional neural network.

Requires CMake >=2.8 (not included)
GTest 1.7.0 (included in 3rdparty folder)

### Installation ###
Once CMake has been installed, you have two options:

1) Generate Xcode project in the build directory:
cmake -G "Xcode" -DCMAKE_INSTALL_PREFIX=../EasyCNNApp_install ../ 
make sure Xcode project is set to use C++11 
(Goto Project->Apple LLVM - Language C++ and set C++ Language Dialect to at least C++11 and
C++ Standard library to LLVM C++ with C++11 support)

2) Modify root CmakeLists.txt file to use C++11 from your system, similar to 
 "set (CMAKE_CXX_FLAGS "-std=c++0x -stdlib=libc++)"
then navigate to the root of the project and issue the following commands:
```bash
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=../EasyCNNApp_install ../
make -j8
make check
make install
```
This will test and install library, header and the app into the project root (folder "EasyCNNApp_install").


### Usage ###
Navigate to EasyCNNApp_install/bin folder in the project root and type ./EasyCNNApp

***Uninstallation*** 
Delete folder 'EasyCNNApp_install' from the root of the project




