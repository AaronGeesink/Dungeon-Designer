#ifndef TRAP_ENCOUNTER_FACTORY_HPP
#define TRAP_ENCOUNTER_FACTORY_HPP

#include "./abstract_encounter_factory.hpp"
#include "./encounter.hpp"

class TrapEncounterFactory : public AbstractEncounterFactory
{
private:
    
public:
    TrapEncounterFactory();
    ~TrapEncounterFactory();
    Encounter* genEncounter();
};

#endif // TRAP_ENCOUNTER_FACTORY_HPP