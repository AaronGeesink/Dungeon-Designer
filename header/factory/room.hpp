#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>

class Room
{
private:
    int id;
    //Encounter encounter;
public:
    Room(int id);
    ~Room();
    void generateEncounter();
    std::string getEncounter();
};

#include "../../src/factory/room.cpp"

#endif // ROOM_HPP
