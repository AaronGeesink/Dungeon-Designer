#ifndef TRAP_HPP
#define TRAP_HPP

#include <string>

class Trap
{
private:
    std::string trap_name;
    std::string effect;
public:
    Trap();
    Trap(std::string name, std::string effect);
    ~Trap();
    std::string getName();
    std::string getEffects();
};

#endif // TRAP_HPP