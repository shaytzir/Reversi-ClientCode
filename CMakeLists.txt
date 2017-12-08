cmake_minimum_required(VERSION 3.8)
project(Ex4)

set(CMAKE_CXX_STANDARD 98)


add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(SOURCE_FILES src/main.cpp src/Board.cpp include/Board.h include/GeneralPlayer.h src/ReversiRules.cpp include/ReversiRules.h src/HumanP.cpp include/HumanP.h src/GameFlow.cpp include/GameFlow.h include/Visualization.h src/Console.cpp include/Console.h include/Cell.h include/Point.h Tests/gtest_main.cpp Tests/Test_Board.cpp Tests/Test_ReversiRules.cpp src/AIPlayer.cpp include/AIPlayer.h Tests/Test_HumanP.cpp Tests/Test_AIPlayer.cpp src/Client.cpp include/Client.h src/RemotePlayer.cpp include/RemotePlayer.h src/LocalPlayer.cpp include/LocalPlayer.h)
add_executable(Ex4 ${SOURCE_FILES} src/Board.cpp include/Board.h include/GeneralPlayer.h src/ReversiRules.cpp include/ReversiRules.h src/HumanP.cpp include/HumanP.h src/GameFlow.cpp include/GameFlow.h include/Visualization.h src/Console.cpp include/Console.h include/Cell.h include/Point.h Tests/gtest_main.cpp Tests/Test_Board.cpp Tests/Test_ReversiRules.cpp src/AIPlayer.cpp include/AIPlayer.h Tests/Test_HumanP.cpp Tests/Test_AIPlayer.cpp src/Client.cpp include/Client.h src/RemotePlayer.cpp include/RemotePlayer.h src/LocalPlayer.cpp include/LocalPlayer.h)

target_link_libraries(Ex4 gtest gtest_main)