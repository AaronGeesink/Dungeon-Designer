#ifndef TRAP_CPP
#define TRAP_CPP

#include <string>
#include <vector>
#include "../../header/factory/trap.hpp"

const std::vector<std::string> possible_traps {
    "Beartrap",
    "Hidden Mine",
    "Arrow Trap",
    "Trap Door",
    "Poison Air"
};

const std::vector<std::string> possible_effects {
    "Weakness",
    "Slowness",
    "Paralysis",
    "Poison"
};

Trap::Trap() {
    this->trap_name = possible_traps[rand() % possible_traps.size()];
    this->effect = possible_effects[rand() % possible_effects.size()];
}

Trap::Trap(std::string name, std::string effect) : trap_name(name), effect(effect) {}

Trap::~Trap() {}

std::string Trap::getName() {
    return this->trap_name;
}

std::string Trap::getEffects() {
    return this->effect;
}

#endif // TRAP_CPP