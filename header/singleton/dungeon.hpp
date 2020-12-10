#ifndef DUNGEON_HPP
#define DUNGEON_HPP

#include "../matrix_graph.hpp"
#include "../factory/room.hpp"
#include "../strategy/dungeon_type.hpp"
#include "../strategy/linear_dungeon_type.hpp"
#include <string>

//enum DungeonTypeCode { LINEAR = 0, BRANCHING = 1, GRIDDED = 2 };

class Dungeon {
	private:
		/* Here will be the instance stored. */
		//static Dungeon* instance;

		DungeonType* dungeonType;

		MatrixGraph<Room> rooms;

		/* Private constructor to prevent instantiating. */
		Dungeon();
		~Dungeon();

	public:
		
		/* Static access method. */
		static Dungeon& getInstance();

		void setDungeonType(DungeonType* dungeonType);
		//void setDungeonType(int dungeonTypeCode);
		void generateDungeon(int numRooms);
		void populateRooms();
		std::string displayDungeon();
};

#endif 