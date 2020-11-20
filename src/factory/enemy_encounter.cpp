#ifndef ENEMY_ENCOUNTER_CPP
#define ENEMY_ENCOUNTER_CPP

#include <string>
#include <sstream>
#include <utility>
#include <vector>
#include "../../header/factory/enemy_encounter.hpp"

const int MAX_ENEMIES = 3;
const int MAX_PER_ENEMY = 5;

EnemyEncounter::EnemyEncounter() {
    int num_enemies = (rand() % MAX_ENEMIES) + 1;
    for (int i=0; i<num_enemies; i++) {
        int num_specific = (rand() % MAX_PER_ENEMY) + 1;
        enemies.push_back(new std::pair<Enemy*, int>(new Enemy(), num_specific));
    }
}

EnemyEncounter::EnemyEncounter(std::vector<std::pair<Enemy*, int>*> enemies) : enemies(enemies) {}

EnemyEncounter::~EnemyEncounter() {
    for(auto enemy : this->enemies) {
        delete enemy->first;
        delete enemy;
    }
}

std::string EnemyEncounter::getEncounter() {
    std::stringstream rtn;
    // Enemy Encounter
    //      3 pirates with 20 health.
    //      9 skeletons with 55 health.
    rtn << "Enemy Encounter!" << std::endl;
    for (int i = 0; i < this->enemies.size(); i++) {
        std::pair<Enemy*, int>* p = this->enemies[i];
        rtn << "\t" << p->second << " " << p->first->getName() << "s with " << p->first->getHealth() << " health.";

        if (i != this->enemies.size() - 1)
            rtn << std::endl;
    }
    return rtn.str();
}

#endif // ENEMY_ENCOUNTER_CPP