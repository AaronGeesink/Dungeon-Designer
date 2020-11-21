#ifndef LOOT_ENCOUNTER_CPP
#define LOOT_ENCOUNTER_CPP

#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include "../../header/factory/loot_encounter.hpp"

const int MAX_LOOT = 5;
const int MAX_PER_LOOT = 5;

LootEncounter::LootEncounter() {
    int num_loot = (rand() % MAX_LOOT) + 1;
    for (int i=0; i<num_loot; i++) {
        int num_specific = (rand() % MAX_PER_LOOT) + 1;
        this->items.push_back(new std::pair<Loot*, int>(new Loot(), num_specific));
    }
}

LootEncounter::LootEncounter(std::vector<std::pair<Loot*, int>*> items) : items(items) {}

LootEncounter::~LootEncounter() {
    for(auto item : this->items) {
        delete item->first;
        delete item;
    }
}

std::string LootEncounter::getEncounter() {
    std::stringstream rtn;
    // Loot Encounter
    //      5 swords
    //      20 golds
    rtn << "Loot Encounter!" << std::endl;
    for (int i = 0; i< this->items.size(); i++) {
        std::pair<Loot*, int>* p = this->items[i];
        rtn << "\t" << p->second << " " << p->first->getName() << "s.";

        if (i != this->items.size() - 1) {
            rtn << std::endl;
        }
    }

    return rtn.str();
}

#endif // LOOT_ENCOUNTER_CPP