#ifndef TRAP_ENCOUNTER_HPP
#define TRAP_ENCOUNTER_HPP

#include <vector>
#include <string>
#include "encounter.hpp"
#include "trap.hpp"

class TrapEncounter : public Encounter
{
private:
    std::vector<Trap> traps;
public:
    TrapEncounter();
    TrapEncounter(std::vector<Trap> traps);
    ~TrapEncounter();
    std::string getEncounter();
    Encounter* clone();
};


#endif // TRAP_ENCOUNTER_HPP