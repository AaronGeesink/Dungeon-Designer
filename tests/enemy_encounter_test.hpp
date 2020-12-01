#ifndef ENEMY_ENCOUNTER_TEST_HPP
#define ENEMY_ENCOUNTER_TEST_HPP

#include "gmock/gmock.h"
#include "iostream"
#include <vector>
#include <utility>

#include "../header/factory/enemy.hpp"
#include "../header/factory/enemy_encounter.hpp"

TEST(EnemyEncounterTest, GetEncounterNotEmpty) {
    EnemyEncounter* enemy = new EnemyEncounter();
	EXPECT_NE(enemy->getEncounter(), "");
    delete enemy;
}

TEST(EnemyEncounterTest, GetEncounterHasEnemy) {
    EnemyEncounter* enemy = new EnemyEncounter();
	EXPECT_THAT(enemy->getEncounter(), ::testing::HasSubstr("Enemy Encounter"));
    delete enemy;
}

TEST(EnemyEncounterTest, SingleEnemy) {
    // Setup list with a single enemy
    std::vector<std::pair<Enemy, int>> enemies;
    enemies.push_back(std::pair<Enemy, int>(Enemy("Joe", 100), 20));

    // Setup the EnemyEncounter, giving it the list of enemies
    EnemyEncounter* enemy = new EnemyEncounter(enemies);

    // Make sure the output is correct
    EXPECT_EQ(enemy->getEncounter(), "Enemy Encounter!\n\t20 Joes with 100 health.");

    // Cleanup
    delete enemy;
}

TEST(EnemyEncounterTest, ThreeEnemies) {
    // Setup list with multiple enemies
    std::vector<std::pair<Enemy, int>> enemies;
    enemies.push_back(std::pair<Enemy, int>(Enemy("Joe", 100), 20));
    enemies.push_back(std::pair<Enemy, int>(Enemy("Foo", 69), 11));
    enemies.push_back(std::pair<Enemy, int>(Enemy("Bar", 4), 20));

    // Setup the EnemyEncounter, giving it the list of enemies
    EnemyEncounter* enemy = new EnemyEncounter(enemies);

    // Make sure the output is correct
    EXPECT_EQ(enemy->getEncounter(), "Enemy Encounter!\n\t20 Joes with 100 health.\n\t11 Foos with 69 health.\n\t20 Bars with 4 health.");

    // Cleanup
    delete enemy;
}

#endif //ENEMY_ENCOUNTER_TEST_HPP
