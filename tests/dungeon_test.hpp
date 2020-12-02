#ifndef DUNGEON_TEST_HPP
#define DUNGEON_TEST_HPP

#include "gtest/gtest.h"

#include "../header/singleton/dungeon.hpp"
#include "../header/strategy/linear_dungeon_type.hpp"


TEST(DungeonTest, DisplayDungeonTest) {
	//Dungeon::getInstance();
	//EXPECT_EQ(dungeon.getInstance(), dungeon);
	EXPECT_EQ(Dungeon::getInstance().displayDungeon(), "Here is the generated dungeon:\n\n\nEncounters for each room:\n");
}

// TODO: CHANGE IMPLEMENTATION OF THIS GenerateDungeonTest AFTER ENCOUNTER GENERATION FOR ROOMS IS FULLY IMPLEMENTED
TEST(DungeonTest, GenerateDungeonTest) {
	Dungeon::getInstance().setDungeonType(new LinearDungeonType());
	Dungeon::getInstance().generateDungeon(10);
	EXPECT_EQ(Dungeon::getInstance().displayDungeon(), "");
}

// TODO: IMPLEMENT A TEST FOR THE POPULATE ROOM FUNCTION THAT CHECKS IF NEW ROOM ENCOUNTERS ARE DIFFERENT THAN OLD ONES
TEST(DungeonTest, populateRoomTest) {
	Dungeon::getInstance().setDungeonType(new LinearDungeonType());
	Dungeon::getInstance().generateDungeon(5);
	EXPECT_EQ(Dungeon::getInstance().displayDungeon(), "");
}

#endif //DUNGEON_TEST_HPP./te