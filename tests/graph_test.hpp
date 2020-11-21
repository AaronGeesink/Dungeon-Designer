#ifndef GRAPH_TEST_HPP
#define GRAPH_TEST_HPP

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../header/matrix_graph.hpp"

TEST(GraphTest, InitializationTest) {
    int numbers[5] = { 1,2,3,4,5 };
    MatrixGraph<int> graph(numbers, 5);

    std::string test = "Here is the adjacency matrix:\n"
        " id  0   1   2   3   4  \n"
        "  0  0   0   0   0   0  \n"
        "  1  0   0   0   0   0  \n"
        "  2  0   0   0   0   0  \n"
        "  3  0   0   0   0   0  \n"
        "  4  0   0   0   0   0  \n";

    EXPECT_EQ(graph.displayGraph(), test);
}

TEST(GraphTest, ZeroInitializationTest) {
    int numbers[5] = { 1,2,3,4,5 };
    MatrixGraph<int> graph(numbers, 0);

    std::string test = "Here is the adjacency matrix:\n"
        " id \n";

    EXPECT_EQ(graph.displayGraph(), test);
}

TEST(GraphTest, GetNodeTest) {
    int numbers[5] = { 0,1,2,3,4 };
    MatrixGraph<int> graph(numbers, 5);

    EXPECT_EQ(graph.getNode(0), 0);
    EXPECT_EQ(graph.getNode(1), 1);
    EXPECT_EQ(graph.getNode(2), 2);
    EXPECT_EQ(graph.getNode(3), 3);
    EXPECT_EQ(graph.getNode(4), 4);
}

TEST(GraphTest, BidirectionalEdgeTest) {
    int numbers[5] = { 0,1,2,3,4 };
    MatrixGraph<int> graph(numbers, 5);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    std::string test = "Here is the adjacency matrix:\n"
        " id  0   1   2   3   4  \n"
        "  0  0   1   0   0   0  \n"
        "  1  1   0   1   0   0  \n"
        "  2  0   1   0   1   0  \n"
        "  3  0   0   1   0   1  \n"
        "  4  0   0   0   1   0  \n";

    EXPECT_EQ(graph.displayGraph(), test);
}

TEST(GraphTest, IdenticalNodesTest) {
    int numbers[5] = { 0,0,0,0,0 };
    MatrixGraph<int> graph(numbers, 5);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    std::string test = "Here is the adjacency matrix:\n"
        " id  0   1   2   3   4  \n"
        "  0  0   1   0   0   0  \n"
        "  1  1   0   1   0   0  \n"
        "  2  0   1   0   1   0  \n"
        "  3  0   0   1   0   1  \n"
        "  4  0   0   0   1   0  \n";

    EXPECT_EQ(graph.displayGraph(), test);
}

TEST(GraphTest, AddVertexTest) {
    int numbers[4] = { 0,1,2,3 };
    MatrixGraph<int> graph(numbers, 4);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);

    graph.addVertex(4);

    graph.addEdge(3, 4);

    std::string test = "Here is the adjacency matrix:\n"
        " id  0   1   2   3   4  \n"
        "  0  0   1   0   0   0  \n"
        "  1  1   0   1   0   0  \n"
        "  2  0   1   0   1   0  \n"
        "  3  0   0   1   0   1  \n"
        "  4  0   0   0   1   0  \n";

    EXPECT_EQ(graph.displayGraph(), test);

    EXPECT_EQ(graph.size(), 5);
    EXPECT_EQ(graph.getNode(4), 4);
    EXPECT_EQ(graph.displayGraph(), test);
}

TEST(GraphTest, ClearGraphTest) {
    int numbers[4] = { 0,1,2,3 };
    MatrixGraph<int> graph(numbers, 4);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);

    graph.clear();

    graph.addVertex(4);
    graph.addVertex(5);
    graph.addVertex(6);
    graph.addVertex(7);
    graph.addVertex(8);

    std::string test = "Here is the adjacency matrix:\n"
        " id  0   1   2   3   4  \n"
        "  0  0   0   0   0   0  \n"
        "  1  0   0   0   0   0  \n"
        "  2  0   0   0   0   0  \n"
        "  3  0   0   0   0   0  \n"
        "  4  0   0   0   0   0  \n";

    EXPECT_EQ(graph.displayGraph(), test);

    EXPECT_EQ(graph.size(), 5);
    EXPECT_EQ(graph.getNode(0), 4);
    EXPECT_EQ(graph.getNode(4), 8);
    EXPECT_EQ(graph.displayGraph(), test);
}

#endif //GRAPH_TEST_HPP