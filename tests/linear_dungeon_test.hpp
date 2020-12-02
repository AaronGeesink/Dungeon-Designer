#ifndef LINEAR_DUNGEON_TEST_HPP
#define LINEAR_DUNGEON_TEST_HPP

#include "gtest/gtest.h"
#include "gmock/gmock.h"

//#include "../header/matrix_graph.hpp"
#include "../header/strategy/linear_dungeon_type.hpp"

TEST(LinearDungeonTest, Generate1RoomLinearDungeonTest) {
    LinearDungeonType* type = new LinearDungeonType();
    MatrixGraph<Room> graph(1);
    Room room(1);
    graph.addVertex(room);
    type->generateDungeon(graph);
    
    string test = "|--| \n"
        "| 1|=\n"
        "|--| \n";

    EXPECT_EQ(type->displayDungeon(graph), test);

    delete type;
}

TEST(LinearDungeonTest, PolymorphsismTest) {
    DungeonType* type = new LinearDungeonType();
    MatrixGraph<Room> graph(1);
    Room room(1);
    graph.addVertex(room);
    type->generateDungeon(graph);

    string test = "|--| \n"
        "| 1|=\n"
        "|--| \n";

    EXPECT_EQ(type->displayDungeon(graph), test);

    delete type;
}

TEST(LinearDungeonTest, Generate2RoomLinearDungeonTest) {
    LinearDungeonType* type = new LinearDungeonType();
    MatrixGraph<Room> graph(2);
    Room room1(1);
    Room room2(2);
    graph.addVertex(room1);
    graph.addVertex(room2);
    type->generateDungeon(graph);

    string test = "|--| |--| \n"
        "| 1|=| 2|=\n"
        "|--| |--| \n";

    EXPECT_EQ(type->displayDungeon(graph), test);

    delete type;
}

TEST(LinearDungeonTest, Generate6RoomLinearDungeonTest) {
    LinearDungeonType* type = new LinearDungeonType();
    MatrixGraph<Room> graph(6);
    for (int i = 0; i < graph.getMaxSize(); i++)
    {
        Room room(i);
        graph.addVertex(room);
    }
    
    type->generateDungeon(graph);

    string test = "|--| |--| |--| |--| |--| |--| \n"
        "| 1|=| 2|=| 3|=| 4|=| 5|=| 6|=\n"
        "|--| |--| |--| |--| |--| |--| \n";

    EXPECT_EQ(type->displayDungeon(graph), test);

    delete type;
}

TEST(LinearDungeonTest, Generate22RoomLinearDungeonTest) {
    LinearDungeonType* type = new LinearDungeonType();
    MatrixGraph<Room> graph(22);
    for (int i = 0; i < graph.getMaxSize(); i++)
    {
        Room room(i);
        graph.addVertex(room);
    }

    type->generateDungeon(graph);

    string test = "|--| |--| |--| |--| |--| |--| |--| |--| |--| |--| \n"
        "| 1|=| 2|=| 3|=| 4|=| 5|=| 6|=| 7|=| 8|=| 9|=|10|=\n"
        "|--| |--| |--| |--| |--| |--| |--| |--| |--| |--| \n\n"
        "|--| |--| |--| |--| |--| |--| |--| |--| |--| |--| \n"
        "|11|=|12|=|13|=|14|=|15|=|16|=|17|=|18|=|19|=|20|=\n"
        "|--| |--| |--| |--| |--| |--| |--| |--| |--| |--| \n\n"
        "|--| |--| \n"
        "|21|=|22|=\n"
        "|--| |--| \n";

    EXPECT_EQ(type->displayDungeon(graph), test);

    delete type;
}

#endif // LINEAR_DUNGEON_TEST_HPP