#include "header/singleton/dungeon_manager.hpp"
#include <time.h>


int main(int argc, char **argv) {
    srand(time(NULL));
    
    DungeonManager manager;
    manager.displayMainMenu();

    return 0;
}
