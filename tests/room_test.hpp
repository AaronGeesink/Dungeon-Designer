#ifndef ROOM_TEST_HPP
#define ROOM_TEST_HPP

#include "gtest/gtest.h"

//#include "../header/factory/room.hpp"
#include "../src/factory/room.cpp"

TEST(RoomTest, GetEncounterNotEmpty) {
    Room* room = new Room(1);

	EXPECT_NE(room->getEncounter(), "");

    delete room;
}

TEST(RoomTest, GenEncounterNoThrow) {
    Room* room = new Room(1);
    
	EXPECT_NO_THROW(room->generateEncounter());

    delete room;
}

#endif //ROOM_TEST_HPP
