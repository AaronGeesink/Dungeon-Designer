#ifndef DUNGEON_CPP
#define DUNGEON_CPP

#include "../../header/singleton/dungeon.hpp"

/* Null, because instance will be initialized on demand. */
//Dungeon* Dungeon::instance = 0;

Dungeon::Dungeon()
{
	
}

Dungeon& Dungeon::getInstance()
{
	static Dungeon instance;
	return instance;
}

void Dungeon::setDungeonType(DungeonType* dungeonType)
{
	this->dungeonType = dungeonType;
}

/*
void Dungeon::setDungeonType(int dungeonTypeCode)
{
	switch (dungeonTypeCode)
	{
		case LINEAR:
			this->dungeonType = new LinearDungeonType();

		case BRANCHING:

		case GRIDDED:

		case default:
			
	}
		
}
*/
void Dungeon::generateDungeon(int numRooms)
{
	this->rooms.clear();
	for (int i = 0; i < numRooms; i++)
	{
		rooms.addVertex(new Room(i));
	}
	dungeonType->generateDungeon(rooms);
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
