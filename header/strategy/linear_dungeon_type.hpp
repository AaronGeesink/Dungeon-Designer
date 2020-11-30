#ifndef LINEAR_DUNGEON_TYPE_HPP
#define LINEAR_DUNGEON_TYPE_HPP

#include "./dungeon_type.hpp"

class LinearDungeonType : public DungeonType
{
private:
public:
	void generateDungeon(MatrixGraph<Room>& rooms);
	std::string displayDungeon(const MatrixGraph<Room>& rooms);
}

#endif // LINEAR_DUNGEON_TYPE_HPP