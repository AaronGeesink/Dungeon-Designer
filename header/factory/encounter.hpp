#ifndef ENCOUNTER_HPP
#define ENCOUNTER_HPP

#include <string>

class Encounter
{
protected:
    std::string encounter_name;
public:
    Encounter(std::string name) : encounter_name(name) {};
    virtual std::string getEncounter() = 0;
};

#endif // ENCOUNTER_HPP
