cmake_minimum_required(VERSION 3.8)
project(Ex4)

set(CMAKE_CXX_STANDARD 98)


add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(SOURCE_FILES main.cpp Board.cpp Board.h GeneralPlayer.h ReversiRules.cpp ReversiRules.h HumanP.cpp HumanP.h GameFlow.cpp GameFlow.h Visualization.h Console.cpp Console.h Cell.h Point.h Tests/gtest_main.cpp Tests/Test_Board.cpp Tests/Test_ReversiRules.cpp AIPlayer.cpp AIPlayer.h Tests/Test_HumanP.cpp Tests/Test_AIPlayer.cpp Client.cpp Client.h RemotePlayer.cpp RemotePlayer.h LocalPlayer.cpp LocalPlayer.h)
add_executable(Ex4 ${SOURCE_FILES} Board.cpp Board.h GeneralPlayer.h ReversiRules.cpp ReversiRules.h HumanP.cpp HumanP.h GameFlow.cpp GameFlow.h Visualization.h Console.cpp Console.h Cell.h Point.h Tests/gtest_main.cpp Tests/Test_Board.cpp Tests/Test_ReversiRules.cpp AIPlayer.cpp AIPlayer.h Tests/Test_HumanP.cpp Tests/Test_AIPlayer.cpp Client.cpp Client.h RemotePlayer.cpp RemotePlayer.h LocalPlayer.cpp LocalPlayer.h)

target_link_libraries(Ex4 gtest gtest_main)