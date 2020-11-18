cmake_minimum_required(VERSION 3.0.0)
project(dungeon VERSION 0.1.0)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
  tests/_unit_tests.cpp
)

ADD_EXECUTABLE(dungeondesigner
   main.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
