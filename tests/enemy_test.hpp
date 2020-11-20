#ifndef ENEMY_TEST_HPP
#define ENEMY_TEST_HPP

#include "gtest/gtest.h"

#include "../header/factory/enemy.hpp"

TEST(EnemyTest, NonEmptyName) {
    Enemy* enemy = new Enemy();

    EXPECT_NE(enemy->getName(), "");

    delete enemy;
}

TEST(EnemyTest, NonZeroHealth) {
    Enemy* enemy = new Enemy();

    EXPECT_GT(enemy->getHealth(), 0);

    delete enemy;
}

TEST(EnemyTest, SetValues) {
    Enemy* enemy = new Enemy("Foo", 20);

    EXPECT_EQ(enemy->getHealth(), 20);
    EXPECT_EQ(enemy->getName(), "Foo");

    delete enemy;
}

#endif //ENEMY_TEST_HPP
