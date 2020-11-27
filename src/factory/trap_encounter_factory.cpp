#ifndef TRAP_ENCOUNTER_FACTORY_CPP
#define TRAP_ENCOUNTER_FACTORY_CPP

#include "../../header/factory/trap_encounter_factory.hpp"
#include "../../header/factory/encounter.hpp"
#include "../../header/factory/trap_encounter.hpp"

TrapEncounterFactory::TrapEncounterFactory() {}

TrapEncounterFactory::~TrapEncounterFactory() {}

Encounter* TrapEncounterFactory::genEncounter() {
    return new TrapEncounter();
}

#endif // TRAP_ENCOUNTER_FACTORY_CPP