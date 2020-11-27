cmake_minimum_required(VERSION 3.0.0)
project(dungeon VERSION 0.1.0)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

# Example adapted from https://github.com/ttroy50/cmake-examples/tree/master/01-basic/C-static-library

####################
# Make the library #
####################

add_library(dungeon_lib STATIC
  src/factory/room.cpp
  src/factory/enemy_encounter.cpp
  src/factory/loot_encounter.cpp
  src/factory/trap_encounter.cpp
  src/factory/enemy.cpp
  src/factory/loot.cpp
  src/factory/trap.cpp
  src/factory/trap_encounter_factory.cpp
  src/factory/loot_encounter_factory.cpp
  
  src/singleton/dungeon_manager.cpp
  src/singleton/dungeon.cpp

)

target_include_directories(dungeon_lib
  PUBLIC 
    ${PROJECT_SOURCE_DIR}/header
)

########################
# Make the executables #
########################

ADD_EXECUTABLE(test
  tests/_unit_tests.cpp
)

ADD_EXECUTABLE(dungeondesigner
  main.cpp
)

# Link our dungeon_lib to our dungeondesigner and test
TARGET_LINK_LIBRARIES(dungeondesigner dungeon_lib)
TARGET_LINK_LIBRARIES(test dungeon_lib)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_LINK_LIBRARIES(test gmock)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
