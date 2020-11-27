#ifndef ABSTRACT_ENCOUNTER_FACTORY_HPP
#define ABSTRACT_ENCOUNTER_FACTORY_HPP

#include "./encounter.hpp"

class AbstractEncounterFactory
{
private:
public:
    // AbstractEncounterFactory();
    ~AbstractEncounterFactory() {};
    virtual Encounter* genEncounter() = 0;
};

#endif // ABSTRACT_ENCOUNTER_FACTORY_HPP