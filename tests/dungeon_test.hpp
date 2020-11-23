#ifndef DUNGEON_TEST_HPP
#define DUNGEON_TEST_HPP

#include "gtest/gtest.h"

#include "../header/singleton/dungeon.hpp"

TEST(DungeonTest, GetInstance) {
	Dungeon* dungeon = dungeon->getInstance();
	EXPECT_EQ(dungeon->getInstance(), dungeon);

}

TEST(DungeonTest, DisplayDungeon) {
	Dungeon* dungeon = dungeon->getInstance();
	EXPECT_EQ(dungeon->displayDungeon(), "");
}

#endif //DUNGEON_TEST_HPP