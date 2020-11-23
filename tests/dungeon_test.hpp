#ifndef DUNGEON_TEST_HPP
#define DUNGEON_TEST_HPP

#include "gtest/gtest.h"

#include "../header/singleton/dungeon.hpp"

TEST(DungeonTest, InstanceDisplayDungeon) {
	Dungeon* dungeon = dungeon->getInstance();
	EXPECT_EQ(dungeon->getInstance(), dungeon);
	EXPECT_EQ(dungeon->displayDungeon(), "");

	delete dungeon;
}

#endif //DUNGEON_TEST_HPP