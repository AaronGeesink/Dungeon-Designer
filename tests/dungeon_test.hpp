#ifndef DUNGEON_TEST_HPP
#define DUNGEON_TEST_HPP

#include "gtest/gtest.h"

#include "../header/singleton/dungeon.hpp"

TEST(DungeonTest, InstanceDisplayDungeon) {
	//Dungeon::getInstance();
	//EXPECT_EQ(dungeon.getInstance(), dungeon);
	EXPECT_EQ(Dungeon::getInstance().displayDungeon(), "");
}

#endif //DUNGEON_TEST_HPP