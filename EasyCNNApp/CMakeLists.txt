project (EasyCNNApp)

add_executable (EasyCNNApp src/EasyCNNApp.cpp)
target_link_libraries (EasyCNNApp CNN)

install (TARGETS EasyCNNApp DESTINATION bin)
