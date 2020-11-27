#ifndef ENEMY_ENCOUNTER_FACTORY_CPP
#define ENEMY_ENCOUNTER_FACTORY_CPP

#include "../../header/factory/enemy_encounter_factory.hpp"
#include "../../header/factory/encounter.hpp"
#include "../../header/factory/enemy_encounter.hpp"

EnemyEncounterFactory::EnemyEncounterFactory() {}

EnemyEncounterFactory::~EnemyEncounterFactory() {}

Encounter* EnemyEncounterFactory::genEncounter() {
    return new EnemyEncounter();
}

#endif // ENEMY_ENCOUNTER_FACTORY_CPP