#include "../../header/strategy/branching_dungeon_type.hpp"

void BranchingDungeonType::generateDungeon(MatrixGraph<Room>& rooms)
{
	// connect half of the rooms together in a linear fashion
	int i;
	for (i = 0; i < rooms.getSize()/2; i++)
	{
		rooms.addEdge(i, i + 1);
	}

	for (i = i + 1; i < rooms.getSize(); i++)
	{
		// pick two different random rooms that have edges on the graph
		int firstRoom = rand() % (i - 1);
		int secondRoom = firstRoom;
		while (firstRoom == secondRoom)
		{
			secondRoom = rand() % (i - 1);
		}

		// connect a new room to two other randomly selected rooms
		rooms.addEdge(i, firstRoom);
		rooms.addEdge(i, secondRoom);
	}
}

std::string BranchingDungeonType::displayDungeon(MatrixGraph<Room>& rooms)
{
	return rooms.displayGraph();
}
