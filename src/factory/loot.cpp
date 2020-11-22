#ifndef LOOT_CPP
#define LOOT_CPP

#include <vector>
#include <string>
#include "../../header/factory/loot.hpp"

const std::vector<std::string> possible_loot {
    "Gold Piece",
    "Sword",
    "Bow",
    "Arrow",
    "Egg",
    "Axe",
    "Enchanted Paper Airplane"
};

Loot::Loot() {
    this->loot_name = possible_loot[rand() % possible_loot.size()];
}

Loot::Loot(std::string name) : loot_name(name) {}

Loot::~Loot() {}

std::string Loot::getName() {
    return this->loot_name;
}

#endif // LOOT_CPP
