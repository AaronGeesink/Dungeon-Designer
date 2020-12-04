#ifndef ROOM_TEST_HPP
#define ROOM_TEST_HPP

#include "gtest/gtest.h"

#include <string>
#include "../header/factory/room.hpp"

TEST(RoomTest, GetEncounterNotEmpty) {
    Room* room = new Room(1);

    EXPECT_NE(room->getRoom(), "");

    delete room;
}

TEST(RoomTest, GenEncounterNoThrow) {
    Room* room = new Room(1);
    
    EXPECT_NO_THROW(room->generateEncounter());

    delete room;
}

TEST(RoomTest, GenDifferentEncounters) {
    Room* room = new Room(1);

    std::string first_encounter = room->getRoom();
    room->generateEncounter();
    std::string second_encounter = room->getRoom();

    // TECHNICALLY, when generateEncounter is called, we /could/ get unlucky and
    // random get the same encounter again, though this is pretty unlikely
    EXPECT_NE(first_encounter, second_encounter);

    delete room;
}

#endif //ROOM_TEST_HPP
