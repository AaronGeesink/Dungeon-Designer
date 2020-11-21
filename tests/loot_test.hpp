#ifndef LOOT_TEST_HPP
#define LOOT_TEST_HPP

#include "gtest/gtest.h"
#include "../../header/factory/loot.hpp"

TEST(LootTest, NonEmptyName) {
    Loot* loot = new Loot();

    EXPECT_NE(loot->getName(), "");

    delete loot;
}

TEST(LootTest, SetEmptyName) {
    Loot* loot = new Loot("");

    EXPECT_EQ(loot->getName(), "");

    delete loot;
}

TEST(LootTest, SetName) {
    Loot* loot = new Loot("Paperclip");

    EXPECT_EQ(loot->getName(), "Paperclip");

    delete loot;
}

#endif //LOOT_TEST_HPP
