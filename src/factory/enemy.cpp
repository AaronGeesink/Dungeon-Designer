#ifndef ENEMY_CPP
#define ENEMY_CPP

#include <vector>
#include <string>
#include "../../header/factory/enemy.hpp"

const std::vector<std::string> possible_enemies {
    "Zombie",
    "Pirate",
    "Monkey",
    "Skeleton",
    "Bigfoot",
    "Gorilla"
};

const int MAX_HEALTH = 100;

Enemy::Enemy() {
    this->enemy_name = possible_enemies[rand() % possible_enemies.size()];
    this->health = (rand() % MAX_HEALTH) + 1;
}

Enemy::Enemy(std::string name, int health) {
    this->enemy_name = name;
    this->health = health;
}

Enemy::~Enemy() {}

std::string Enemy::getName() {
    return this->enemy_name;
}

int Enemy::getHealth() {
    return this->health;
}

#endif // ENEMY_CPP
