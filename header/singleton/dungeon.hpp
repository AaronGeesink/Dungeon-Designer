#ifndef DUNGEON_HPP
#define DUNGEON_HPP

#include "../matrix_graph.hpp"
#include "../factory/room.hpp"
#include <string>

class Dungeon {
	private:
		/* Here will be the instance stored. */
		//static Dungeon* instance;

		//DungeonType* type;

		MatrixGraph<Room> rooms;

		/* Private constructor to prevent instancing. */
		Dungeon();

	public:
		/* Static access method. */
		static Dungeon& getInstance();

		void generateDungeon();
		void populateRooms();
		std::string displayDungeon();
};

#endif 