#ifndef ENEMY_ENCOUNTER_FACTORY_HPP
#define ENEMY_ENCOUNTER_FACTORY_HPP

#include "./abstract_encounter_factory.hpp"
#include "./encounter.hpp"

class EnemyEncounterFactory : public AbstractEncounterFactory
{
private:
    
public:
    EnemyEncounterFactory();
    ~EnemyEncounterFactory();
    Encounter* genEncounter();
};

#endif // ENEMY_ENCOUNTER_FACTORY_HPP