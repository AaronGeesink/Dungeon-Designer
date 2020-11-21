#ifndef LOOT_HPP
#define LOOT_HPP

#include <string>

class Loot
{
private:
    std::string loot_name;
public:
    Loot();
    Loot(std::string name);
    ~Loot();
    std::string getName();
};

#endif // LOOT_HPP