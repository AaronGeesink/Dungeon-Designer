#ifndef ENEMY_ENCOUNTER_FACTORY_TEST_HPP
#define ENEMY_ENCOUNTER_FACTORY_TEST_HPP

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../header/factory/abstract_encounter_factory.hpp"
#include "../header/factory/enemy_encounter_factory.hpp"

TEST(EnemyEncounterFactoryTest, EncounterNotEmpty) {
    AbstractEncounterFactory* factory = new EnemyEncounterFactory();
    Encounter* enc = factory->genEncounter();

    EXPECT_NE(enc->getEncounter(), "");

    delete enc;
    delete factory;
}

TEST(EnemyEncounterFactoryTest, GetEncounterHasEnemy) {
    AbstractEncounterFactory* factory = new EnemyEncounterFactory();
    Encounter* enc = factory->genEncounter();

    EXPECT_THAT(enc->getEncounter(), ::testing::HasSubstr("Enemy Encounter!"));

    delete enc;
    delete factory;
}

#endif // ENEMY_ENCOUNTER_FACTORY_TEST_HPP