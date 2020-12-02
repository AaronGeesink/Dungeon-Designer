#ifndef ENCOUNTER_HPP
#define ENCOUNTER_HPP

#include <string>

class Encounter
{
public:
    virtual ~Encounter() {};
    virtual std::string getEncounter() = 0;
    virtual Encounter* clone() = 0;
};

#endif // ENCOUNTER_HPP
