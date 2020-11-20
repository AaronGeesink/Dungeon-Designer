#ifndef DUNGEON_MANAGER_CPP
#define DUNGEON_MANAGER_CPP

#include "../header/dungeonManager.hpp"

DungeonManager::DungeonManager()
{
}

void DungeonManager::displayMainMenu() {
	int choice;

	cout << "Tabletop RPG Dungeon Designer\n\n"
		<< "Options:\n"
		<< "1. Generate a dungeon\n"
		<< "2. Display the most recent dungeon\n"
		<< "3. Quit program\n\n"
		<< "Please select an option: ";

	cin >> choice;

    switch (choice) {
        case 1:
            //displayGenerationMenu();
            break;

        case 2:
			//displayDungeonDisplayMenu
            break;

        case 3:
			exit(0);
            break;

        default:
            cout << "\nInvalid input, please choose again\n\n";
			displayMainMenu();
			break;
    }
}

#endif