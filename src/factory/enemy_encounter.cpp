#ifndef ENEMY_ENCOUNTER_CPP
#define ENEMY_ENCOUNTER_CPP

#include <string>
#include <sstream>
#include <utility>
#include "../../header/factory/enemy_encounter.hpp"

const int MAX_ENEMIES = 3;
const int MAX_PER_ENEMY = 5;

EnemyEncounter::EnemyEncounter() : Encounter("Enemy") {
    int num_enemies = (rand() % MAX_ENEMIES) + 1;
    for (int i=0; i<num_enemies; i++) {
        int num_specific = (rand() % MAX_PER_ENEMY) + 1;
        enemies.push_back(new std::pair<Enemy*, int>(new Enemy(), num_specific));
    }
}

EnemyEncounter::~EnemyEncounter() {
    for(auto enemy : this->enemies) {
        delete enemy->first;
        delete enemy;
    }
}

std::string EnemyEncounter::getEncounter() {
    std::stringstream rtn;
    rtn << "This room contains: " << this->encounter_name;
    for (int i = 0; i < this->enemies.size(); i++) {
        std::pair<Enemy*, int>* p = this->enemies[i];
        // There are 3 pirates with 20 health.
        // There are 9 skeletons with 55 health.
        rtn << "There are " << p->second << " " << p->first->getName() << "s with " << p->first->getHealth() << " health." << std::endl;
    }
    return rtn.str();
}

#endif // ENEMY_ENCOUNTER_CPP