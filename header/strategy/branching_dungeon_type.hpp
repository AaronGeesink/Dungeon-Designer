#ifndef BRANCHING_DUNGEON_TYPE_HPP
#define BRANCHING_DUNGEON_TYPE_HPP

#include "dungeon_type.hpp"

class BranchingDungeonType : public DungeonType
{
private:
public:
	void generateDungeon(MatrixGraph<Room>& rooms);
	std::string displayDungeon(MatrixGraph<Room>& rooms);
};

#endif // BRANCHING_DUNGEON_TYPE_HPP