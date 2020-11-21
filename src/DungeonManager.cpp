#ifndef DUNGEON_MANAGER_CPP
#define DUNGEON_MANAGER_CPP

#include "../header/dungeonManager.hpp"

DungeonManager::DungeonManager()
{
}

void DungeonManager::displayMainMenu() {
	
	int choice;
	std::cin.exceptions(std::ios_base::failbit);

	std::cout << "Tabletop RPG Dungeon Designer\n"
		<< "Options:\n"
		<< "1. Generate a dungeon\n"
		<< "2. Display the most recent dungeon\n"
		<< "3. Quit program\n"
		<< "Please select an option: ";

	try {
		std::cin >> choice;
		if (!(choice >=1 && choice <=3))
			throw std::out_of_range("Please input a valid choice");
	}
	catch (const std::out_of_range & e) {
		std::cout << "\n" << e.what() << "\n\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		displayMainMenu();
	}
	catch (const std::ios_base::failure&) {
		std::cout << "\nPlease enter numbers only!\n" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		displayMainMenu();
	}

    switch (choice) {
        case 1:
            //displayGenerationMenu();
            break;

        case 2:
			//displayDungeonDisplayMenu();
            break;

        case 3:
			exit(0);
            break;

        //default:
          
    }
}

#endif