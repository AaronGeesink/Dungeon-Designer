#ifndef DUNGEON_MANAGER_CPP
#define DUNGEON_MANAGER_CPP

#include "../header/dungeonManager.hpp"

DungeonManager::DungeonManager()
{
}

void DungeonManager::displayMainMenu() {
	char choice = '';

	cout << "Tabletop RPG Dungeon Designer\n\n"
		<< "Options:\n"
		<< "1. Generate a dungeon\n"
		<< "2. Display the most recent dungeon\n"
		<< "3. Quit program\n\n"
		<< "Please select an option: "

	cin >> choice;


}

#endif