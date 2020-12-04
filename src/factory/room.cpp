#ifndef ROOM_CPP
#define ROOM_CPP

#include <stdlib.h>
#include <sstream>
#include <iostream>
#include "../../header/factory/room.hpp"
#include "../../header/factory/encounter.hpp"
#include "../../header/factory/enemy_encounter.hpp"
#include "../../header/factory/abstract_encounter_factory.hpp"
#include "../../header/factory/enemy_encounter_factory.hpp"
#include "../../header/factory/loot_encounter_factory.hpp"
#include "../../header/factory/trap_encounter_factory.hpp"

Room::Room() : id(-1), encounter(nullptr) {
    this->generateEncounter();
}

Room::Room(int id) : id(id), encounter(nullptr) {
    this->generateEncounter();
}

// Copy constructor
Room::Room(const Room& other) : id(other.id), encounter(nullptr) {
    this->encounter = other.encounter->clone();
}

// Copy assignment
Room& Room::operator=(const Room& other) {
    delete this->encounter;
    this->id = other.id;
    this->encounter = other.encounter->clone();
    return *this;
}

Room::~Room() {
    delete this->encounter;
}

void Room::generateEncounter() {
    delete this->encounter;

    int encounter_type = rand() % 3;
    AbstractEncounterFactory* factory = nullptr;
    switch (encounter_type)
    {
    case 0:
        factory = new TrapEncounterFactory();
        break;
    case 1:
        factory = new EnemyEncounterFactory();
        break;
    case 2:
        factory = new LootEncounterFactory();
        break;
    default:
        // You should never get here, if for some reason you do, throw an exception.
        throw -1;
    }

    // factory should not be null at this point, but check just incase?
    if (factory == nullptr) throw -1;

    this->encounter = factory->genEncounter();

    delete factory;
}

std::string Room::getRoom() {
    std::stringstream rtn;
    rtn << "Room " << this->id << ": ";
    rtn << this->encounter->getEncounter();

    return rtn.str();
}

#endif // ROOM_CPP
