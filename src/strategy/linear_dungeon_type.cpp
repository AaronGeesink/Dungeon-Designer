#include "../../header/strategy/linear_dungeon_type.hpp"

void LinearDungeonType::generateDungeon(MatrixGraph<Room>& rooms)
{
	for (int i = 0; i < rooms.size() - 1; i++)
	{
		rooms.addEdge(i, i + 1);
	}
}

std::string LinearDungeonType::displayDungeon(const MatrixGraph<Room>& rooms)
{
	// TODO: IMPLEMENT DISPLAY LINEAR DUNGEON FUNCTION
	return "TODO: IMPLEMENT DISPLAY LINEAR DUNGEON FUNCTION";
}
