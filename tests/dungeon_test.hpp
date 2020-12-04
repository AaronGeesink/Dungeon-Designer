#ifndef DUNGEON_TEST_HPP
#define DUNGEON_TEST_HPP

#include "gtest/gtest.h"
#include <string>

#include "../header/singleton/dungeon.hpp"
#include "../header/strategy/linear_dungeon_type.hpp"


TEST(DungeonTest, DisplayDungeonTest) {
	//Dungeon::getInstance();
	//EXPECT_EQ(dungeon.getInstance(), dungeon);
	EXPECT_EQ(Dungeon::getInstance().displayDungeon(), "Here is the generated dungeon:\n\n\nEncounters for each room:\n");
}

TEST(DungeonTest, GenerateDungeonTest) {
	Dungeon::getInstance().setDungeonType(new LinearDungeonType());
	Dungeon::getInstance().generateDungeon(10);
	EXPECT_NE(Dungeon::getInstance().displayDungeon(), "");
}

TEST(DungeonTest, populateRoomTest) {
	Dungeon::getInstance().setDungeonType(new LinearDungeonType());
	Dungeon::getInstance().generateDungeon(5);
	std::string first_gen = Dungeon::getInstance().displayDungeon();
	Dungeon::getInstance().populateRooms();
	std::string second_gen = Dungeon::getInstance().displayDungeon();
	EXPECT_NE(first_gen, second_gen);
}

#endif //DUNGEON_TEST_HPP