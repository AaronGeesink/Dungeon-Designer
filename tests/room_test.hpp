#ifndef ROOM_TEST_HPP
#define ROOM_TEST_HPP

#include "gtest/gtest.h"

#include "src/factory/room.cpp"

TEST(RoomTest, SubEvaluateNonZero) {
    Room* room = new Room(1);
	EXPECT_EQ(room->getEncounter(), "Encounters have not been implemented.");
}

#endif //ROOM_TEST_HPP