#ifndef LOOT_ENCOUNTER_FACTORY_CPP
#define LOOT_ENCOUNTER_FACTORY_CPP

#include "../../header/factory/loot_encounter_factory.hpp"
#include "../../header/factory/encounter.hpp"
#include "../../header/factory/loot_encounter.hpp"

LootEncounterFactory::LootEncounterFactory() {}

LootEncounterFactory::~LootEncounterFactory() {}

Encounter* LootEncounterFactory::genEncounter() {
    return new LootEncounter();
}

#endif // LOOT_ENCOUNTER_FACTORY_CPP