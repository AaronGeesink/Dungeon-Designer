#include <iostream>

#include "src/factory/room.cpp"

int main(int, char**) {
    Room* room = new Room(1);
    std::cout << room->getEncounter();
}
