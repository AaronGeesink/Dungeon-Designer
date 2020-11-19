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

#endif // ROOM_HPP
