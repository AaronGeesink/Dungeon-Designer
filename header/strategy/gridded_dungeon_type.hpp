#ifndef GRIDDED_DUNGEON_TYPE_HPP
#define GRIDDED_DUNGEON_TYPE_HPP

#include "dungeon_type.hpp"

class GriddedDungeonType : public DungeonType
{
private:
public:
	void generateDungeon(MatrixGraph<Room>& rooms);
	std::string displayDungeon(MatrixGraph<Room>& rooms);
};

#endif // GRIDDED_DUNGEON_TYPE_HPP