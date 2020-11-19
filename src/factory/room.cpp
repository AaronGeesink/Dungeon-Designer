#ifndef ROOM_CPP
#define ROOM_CPP

#include <stdlib.h>

Room::Room(int id) : id(id) {
    this->generateEncounter();
}

Room::~Room() {
    // TODO
    //delete this->encounter;
}

void Room::generateEncounter() {
    // TODO: Finish implementation once Encounter has been finished

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
    case 3:
        // factory = new LootEncounterFactory();
        break;
    default:
        // You should never get here, if for some reason you do, throw an exception.
        throw;
    }

    // factory should not be null at this point, but check just incase?
    // if (factory == nullptr) throw;

    // this->encounter = factory.genEncounter();
}

std::string Room::getEncounter() {
    return "Encounters have not been implemented.";
}

#endif // ROOM_CPP
