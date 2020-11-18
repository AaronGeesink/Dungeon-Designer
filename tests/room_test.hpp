#ifndef ROOM_TEST_HPP
#define ROOM_TEST_HPP

#include "gtest/gtest.h"

#include "../header/factory/room.hpp"

TEST(RoomTest, RoomGetEncounter) {
    Room* room = new Room(1);
	EXPECT_EQ(room->getEncounter(), "Encounters have not been implemented.");
}

#endif //ROOM_TEST_HPP
