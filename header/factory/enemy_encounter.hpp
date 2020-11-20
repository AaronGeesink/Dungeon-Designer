#ifndef ENEMY_ENCOUNTER_HPP
#define ENEMY_ENCOUNTER_HPP

#include <vector>
#include <string>
#include <utility>
#include "./encounter.hpp"
#include "./enemy.hpp"

class EnemyEncounter : Encounter
{
private:
    std::vector<std::pair<Enemy*, int>*> enemies;
public:
    EnemyEncounter();
    EnemyEncounter(std::vector<std::pair<Enemy*, int>*> enemies);
    ~EnemyEncounter();
    std::string getEncounter();
};

#include "../../src/factory/enemy_encounter.cpp"

#endif // ENEMY_ENCOUNTER_HPP