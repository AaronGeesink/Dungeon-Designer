#ifndef DUNGEON_MANAGER_CPP
#define DUNGEON_MANAGER_CPP

#include "../../header/singleton/dungeon_manager.hpp"
#include "../../header/strategy/linear_dungeon_type.hpp"
#include "../../header/strategy/branching_dungeon_type.hpp"

DungeonManager::DungeonManager()
{ }

void DungeonManager::displayMainMenu() {
	int choice;
	//std::cin.exceptions(std::ios_base::failbit);

	while (true)
	{
		clearScreen();
		std::cout << "Tabletop RPG Dungeon Designer\n"
			<< "Options:\n"
			<< "1. Generate a dungeon\n"
			<< "2. Display the most recent dungeon\n"
			<< "3. Quit program\n"
			<< "Please select an option: ";

		try {
			std::cin >> choice;
			if (!(choice >= 1 && choice <= 3))
				throw std::out_of_range("Please input a valid choice");

			switch (choice) {
			case 1:
				displayGenerationMenu();
				break;

			case 2:
				displayDungeonDisplayMenu();
				break;

			case 3:
				std::cout << "\nThank you for using Dungeon Designer!\n";
				exit(0);
				break;
			}
		}
		catch (const std::out_of_range & e) {
			//std::cout << "\n" << e.what() << "\n\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		catch (const std::ios_base::failure&) {
			//std::cout << "\nPlease enter numbers only!\n" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

	}
	
}

void DungeonManager::displayGenerationMenu()
{
	int choice;
	//std::cin.exceptions(std::ios_base::failbit);

	while (true)
	{
		clearScreen();
		std::cout << "What kind of dungeon would you like to generate?\n"
			<< "Options:\n"
			<< "1. Generate a Linear Dungeon\n"
			<< "2. Generate a Branching Dungeon\n"
			<< "3. Generate a Gridded Dungeon\n"
			<< "4. Return to Main Menu\n"
			<< "Please select an option: ";

		try {
			std::cin >> choice;
			if (!(choice >= 1 && choice <= 4))
				throw std::out_of_range("Please input a valid choice");

			DungeonType* type;
			switch (choice) {
			case 1:
				type = new LinearDungeonType();
				Dungeon::getInstance().setDungeonType(type);
				generateDungeon();
				displayDungeonDisplayMenu();
				break;

			case 2:
				type = new BranchingDungeonType();
				Dungeon::getInstance().setDungeonType(type);
				generateDungeon();
				displayDungeonDisplayMenu();
				break;

			case 3:
				displayDungeonDisplayMenu();
				generateDungeon();
				break;

			case 4:
				displayMainMenu();
				break;
			}
		}
		catch (const std::out_of_range & e) {
			//std::cout << "\n" << e.what() << "\n\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		catch (const std::ios_base::failure&) {
			//std::cout << "\nPlease enter numbers only!\n" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}

void DungeonManager::displayDungeonDisplayMenu() {
	int choice;
	//std::cin.exceptions(std::ios_base::failbit);

	while (true)
	{
		clearScreen();
		std::cout << Dungeon::getInstance().displayDungeon()
			<< "\nOptions:\n"
			<< "1. Regenerate encounters\n"
			<< "2. Generate a new dungeon layout\n"
			<< "3. Return to Main Menu\n"
			<< "Please select an option: ";

		try {
			std::cin >> choice;
			if (!(choice >= 1 && choice <= 3))
				throw std::out_of_range("Please input a valid choice");

			switch (choice) {
			case 1:
				Dungeon::getInstance().populateRooms();
				displayDungeonDisplayMenu();
				break;

			case 2:
				generateDungeon();
				displayDungeonDisplayMenu();
				break;

			case 3:

				displayMainMenu();
				break;
			}
		}
		catch (const std::out_of_range & e) {
			//std::cout << "\n" << e.what() << "\n\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		catch (const std::ios_base::failure&) {
			//std::cout << "\nPlease enter numbers only!\n" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}

void DungeonManager::generateDungeon()
{	
	int numRooms;
	bool loop = true;
	while (loop == true)
	{
		try
		{
			std::cout << "How many rooms? (0 to 30): ";
			std::cin >> numRooms;

			if (!(numRooms >= 0 && numRooms <= 30))
				throw std::out_of_range("Please input a valid number of rooms");

			Dungeon::getInstance().generateDungeon(numRooms);
			Dungeon::getInstance().populateRooms();

			loop = false;
		}
		catch (const std::out_of_range& e) {
			std::cout << "\n" << e.what() << "\n\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		catch (const std::ios_base::failure&) {
			std::cout << "\nPlease enter numbers only!\n" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}	
}

void DungeonManager::clearScreen()
{
	std::cout << std::string(100, '\n');
}

#endif