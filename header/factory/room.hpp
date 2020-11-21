#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>
#include "./encounter.hpp"

class Room
{
private:
    int id;
    Encounter* encounter;
public:
    Room(int id);
    ~Room();
    void generateEncounter();
    std::string getRoom();
};

#endif // ROOM_HPP
