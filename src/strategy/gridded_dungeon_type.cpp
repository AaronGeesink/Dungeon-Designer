#include "../../header/strategy/gridded_dungeon_type.hpp"

void GriddedDungeonType::generateDungeon(MatrixGraph<Room>& rooms)
{
	// connect the first 2 rooms of the dungeon
	if (rooms.getSize() > 1)
		rooms.addEdge(0, 1);

	// randomly connect each room of the dungeon to two other rooms
	for (int i = 2; i < rooms.getSize(); i++)
	{
		// pick two different random rooms that have edges on the graph
		int firstRoom = rand() % i;
		int secondRoom = firstRoom;
		while (firstRoom == secondRoom)
		{
			secondRoom = rand() % i;
		}

		// connect a new room to two other randomly selected rooms
		rooms.addEdge(i, firstRoom);
		rooms.addEdge(i, secondRoom);
	}
}

std::string GriddedDungeonType::displayDungeon(MatrixGraph<Room>& rooms)
{
	return rooms.displayGraph();
}
