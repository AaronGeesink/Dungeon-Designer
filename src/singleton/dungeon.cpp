#ifndef DUNGEON_CPP
#define DUNGEON_CPP

#include "../../header/singleton/dungeon.hpp"

/* Null, because instance will be initialized on demand. */
//Dungeon* Dungeon::instance = 0;

Dungeon::Dungeon()
{
	dungeonType = new LinearDungeonType();
}

Dungeon::~Dungeon()
{
	delete dungeonType;
}

Dungeon& Dungeon::getInstance()
{
	static Dungeon instance;
	return instance;
}

void Dungeon::setDungeonType(DungeonType* dungeonType)
{
	delete this->dungeonType;
	this->dungeonType = dungeonType;
}

void Dungeon::generateDungeon(int numRooms)
{
	this->rooms.clear();

	for (int i = 0; i < numRooms; i++)
	{
		Room room(i + 1);
		room.generateEncounter();
		rooms.addVertex(room);
	}
	dungeonType->generateDungeon(rooms);
}

void Dungeon::populateRooms()
{
	for (int i = 0; i < rooms.getSize(); i++)
	{
		Room room(i + 1);
		room.generateEncounter();
		rooms.replaceVertex(i, room);
	}
}

std::string Dungeon::displayDungeon()
{
	std::stringstream rtn;

	rtn << "Here is the generated dungeon:\n\n"
		<< dungeonType->displayDungeon(rooms)
		<< "\nEncounters for each room:\n";
	for (int i = 0; i < rooms.getSize(); i++)
	{
		rtn << rooms.getVertex(i).getRoom() << "\n";
	}

	return rtn.str();
}

#endif
