#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>

class Enemy
{
private:
    std::string enemy_name;
    int health;
public:
    Enemy();
    ~Enemy();
    std::string getName();
    int getHealth();
};

#include "../../src/factory/enemy.cpp"

#endif // ENEMY_HPP