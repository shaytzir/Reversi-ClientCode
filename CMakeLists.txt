cmake_minimum_required(VERSION 3.8)
project(Ex4)

set(CMAKE_CXX_STANDARD 98)


add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(SOURCE_FILES main.cpp GeneralPlayer.h Board.cpp Board.h AIPlayer.cpp AIPlayer.h Cell.h Client.cpp Client.h Console.cpp Console.h GameFlow.cpp GameFlow.h HumanP.cpp HumanP.h RemotePlayer.cpp RemotePlayer.h Point.h ReversiRules.cpp ReversiRules.h Visualization.h Tests/gtest_main.cpp Tests/Test_AIPlayer.cpp Tests/Test_Board.cpp Tests/Test_HumanP.cpp Tests/Test_ReversiRules.cpp)
add_executable(Ex4 ${SOURCE_FILES} GeneralPlayer.h Board.cpp Board.h AIPlayer.cpp AIPlayer.h Cell.h Client.cpp Client.h Console.cpp Console.h GameFlow.cpp GameFlow.h HumanP.cpp HumanP.h RemotePlayer.cpp RemotePlayer.h Point.h ReversiRules.cpp ReversiRules.h Visualization.h Tests/gtest_main.cpp Tests/Test_AIPlayer.cpp Tests/Test_Board.cpp Tests/Test_HumanP.cpp Tests/Test_ReversiRules.cpp)

target_link_libraries(Ex4 gtest gtest_main)