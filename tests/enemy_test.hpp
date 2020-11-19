#ifndef ENEMY_TEST_HPP
#define ENEMY_TEST_HPP

#include "gtest/gtest.h"

#include "../header/factory/enemy.hpp"

TEST(EnemyTest, NonEmptyName) {
    Enemy* enemy = new Enemy();

    ASSERT_NE(enemy->getName(), "");

    delete enemy;
}

TEST(EnemyTest, NonZeroHealth) {
    Enemy* enemy = new Enemy();

    ASSERT_GT(enemy->getHealth(), 0);

    delete enemy;
}

#endif //ENEMY_TEST_HPP
