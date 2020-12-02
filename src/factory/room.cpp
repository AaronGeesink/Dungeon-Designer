#ifndef ROOM_CPP
#define ROOM_CPP

#include <stdlib.h>
#include <sstream>
#include <iostream>
#include "../../header/factory/room.hpp"
#include "../../header/factory/encounter.hpp"
#include "../../header/factory/enemy_encounter.hpp"

Room::Room() : id(-1), encounter(nullptr) {
    // std::cout << "Default Constructor Started" << std::endl;
    this->generateEncounter();
    // std::cout << "Default Constructor Finished" << std::endl;
}

Room::Room(int id) : id(id), encounter(nullptr) {
    // std::cout << "Id Constructor Started" << std::endl;
    this->generateEncounter();
    // std::cout << "Id Constructor Finished" << std::endl;
}

// Copy constructor
Room::Room(const Room& other) : id(other.id), encounter(nullptr) {
    // std::cout << "Copy Constructor Started" << std::endl;
    this->encounter = other.encounter->clone();
    // std::cout << "Copy Constructor Finished" << std::endl;
}

// Copy assignment
Room& Room::operator=(const Room& other) {
    // std::cout << "Copy Assignment Started" << std::endl;
    delete this->encounter;
    this->id = other.id;
    this->encounter = other.encounter->clone();
    // std::cout << "Copy Assignment Finished" << std::endl;
    return *this;
}

Room::~Room() {
    // std::cout << "Deconstructor Started" << std::endl;
    delete this->encounter;
    // std::cout << "Deconstructor Finished" << std::endl;
}

void Room::generateEncounter() {
    // TODO: Finish implementation once AbstractFactory for encounters has been finished
    // std::cout << "Generate Encounter Started" << std::endl;
    delete this->encounter;

    int encounter_type = rand() % 3;
    // AbstractEncounterFactory factory = nullptr;
    switch (encounter_type)
    {
    case 0:
        // factory = new TrapEncounterFactory();
        break;
    case 1:
        // factory = new EnemyEncounterFactory();
        break;
    case 2:
        // factory = new LootEncounterFactory();
        break;
    default:
        // You should never get here, if for some reason you do, throw an exception.
        throw -1;
    }


    // factory should not be null at this point, but check just incase?
    // if (factory == nullptr) throw -1;

    // this->encounter = factory.genEncounter();
    this->encounter = new EnemyEncounter();
    // std::cout << "Generate Encounter Finished" << std::endl;
}

std::string Room::getRoom() {
    // std::cout << "getRoom Started" << std::endl;
    std::stringstream rtn;
    rtn << "Room " << this->id << ": ";
    rtn << this->encounter->getEncounter();

    // std::cout << "getRoom Finished" << std::endl;
    return rtn.str();
}

#endif // ROOM_CPP
