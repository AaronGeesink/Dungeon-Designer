#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "room_test.hpp"
#include "graph_test.hpp"
#include "enemy_encounter_test.hpp"
#include "enemy_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
