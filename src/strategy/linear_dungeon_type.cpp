#include "../../header/strategy/linear_dungeon_type.hpp"
#include <iomanip>

void LinearDungeonType::generateDungeon(MatrixGraph<Room>& rooms)
{
	for (int i = 0; i < rooms.getSize() - 1; i++)
	{
		rooms.addEdge(i, i + 1);
	}
}

std::string LinearDungeonType::displayDungeon(MatrixGraph<Room>& rooms)
{
	std::stringstream rtn;
	
	// display the rooms in sets of 5
	int i = 0;
	while (i < rooms.getSize())
	{
		// case to display the last few rooms if they are not divisible by 5
		if ((rooms.getSize() - i) % 10 != 0 && (rooms.getSize() - i) < 10)
		{

			for (int j = i; j < rooms.getSize(); j++)
			{
				rtn << "|--| ";
			}
			rtn << "\n";
			for (int j = i; j < rooms.getSize(); j++)
			{
				rtn << "|" << std::setw(2) << j + 1 << "|=";
			}
			rtn << "\n";
			for (int j = i; j < rooms.getSize(); j++)
			{
				rtn << "|--| ";
				i++;
			}
			rtn << "\n";
		}

		else
		{
			for (int j = i; j < i + 10; j++)
			{
				rtn << "|--| ";
			}
			rtn << "\n";
			for (int j = i; j < i + 10; j++)
			{
				rtn << "|" << std::setw(2) << j + 1<< "|=";
			}
			rtn << "\n";
			for (int j = 0; j < 10; j++)
			{
				rtn << "|--| ";
				i++;
			}
			rtn << "\n\n";
		}
	}
	
	return rtn.str();
}
