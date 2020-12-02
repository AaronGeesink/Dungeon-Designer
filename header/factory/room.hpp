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
    Room();
    Room(int id);
    ~Room();
    void generateEncounter();
    std::string getRoom();
    Room(const Room& other);
    Room& operator=(const Room& other);
};

#endif // ROOM_HPP
