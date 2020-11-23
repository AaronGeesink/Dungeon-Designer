#ifndef DUNGEON_CPP
#define DUNGEON_CPP

#include "../../header/singleton/dungeon.hpp"

/* Null, because instance will be initialized on demand. */
Dungeon* Dungeon::instance = 0;

Dungeon::Dungeon()
{}

Dungeon* Dungeon::getInstance()
{
	if (instance == 0)
	{
		instance = new Dungeon();
	}

	return instance;
}

void Dungeon::generateDungeon()
{
	// TODO: Implement
}

void Dungeon::populateRooms()
{
	// TODO: Implement
}

std::string Dungeon::displayDungeon()
{
	// TODO: Implement
	return "";
}

#endif
