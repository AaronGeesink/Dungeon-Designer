#ifndef ENEMY_ENCOUNTER_TEST_HPP
#define ENEMY_ENCOUNTER_TEST_HPP

#include "gmock/gmock.h"
#include "iostream"

#include "../header/factory/enemy_encounter.hpp"

TEST(EnemyEncounterTest, EnemyGetEncounterNotEmpty) {
    EnemyEncounter* enemy = new EnemyEncounter();
	EXPECT_NE(enemy->getEncounter(), "");
    delete enemy;
}

TEST(EnemyEncounterTest, EnemyGetEncounterHasEnemy) {
    EnemyEncounter* enemy = new EnemyEncounter();
	EXPECT_THAT(enemy->getEncounter(), ::testing::HasSubstr("Enemy"));
    delete enemy;
}

#endif //ENEMY_ENCOUNTER_TEST_HPP
