#ifndef GRAPH_TEST_HPP
#define GRAPH_TEST_HPP

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../header/matrix_graph.hpp"

TEST(GraphTest, NoParameterConstructorTest) {
    MatrixGraph<int> graph;

    std::string test = "Here is the adjacency matrix:\n"
        " id \n";

    EXPECT_EQ(graph.displayGraph(), test);
    EXPECT_EQ(graph.getSize(), 0);
    EXPECT_EQ(graph.getMaxSize(), 0);

    graph.addVertex(0);
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addVertex(4);

    test = "Here is the adjacency matrix:\n"
        " id  0   1   2   3   4  \n"
        "  0  0   0   0   0   0  \n"
        "  1  0   0   0   0   0  \n"
        "  2  0   0   0   0   0  \n"
        "  3  0   0   0   0   0  \n"
        "  4  0   0   0   0   0  \n";

    EXPECT_EQ(graph.displayGraph(), test);
    EXPECT_EQ(graph.getSize(), 5);
    EXPECT_EQ(graph.getMaxSize(), 6);
}

TEST(GraphTest, SingleParameterConstructorTest) {
    MatrixGraph<int> graph(5);

    std::string test = "Here is the adjacency matrix:\n"
        " id \n";

    EXPECT_EQ(graph.displayGraph(), test);
    EXPECT_EQ(graph.getSize(), 0);
    EXPECT_EQ(graph.getMaxSize(), 5);

    graph.addVertex(0);
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addVertex(4);

    test = "Here is the adjacency matrix:\n"
        " id  0   1   2   3   4  \n"
        "  0  0   0   0   0   0  \n"
        "  1  0   0   0   0   0  \n"
        "  2  0   0   0   0   0  \n"
        "  3  0   0   0   0   0  \n"
        "  4  0   0   0   0   0  \n";

    EXPECT_EQ(graph.displayGraph(), test);
    EXPECT_EQ(graph.getSize(), 5);
    EXPECT_EQ(graph.getMaxSize(), 5);
}

TEST(GraphTest, NegativeSingleParameterConstructorTest) {

    ASSERT_ANY_THROW(MatrixGraph<int> graph(-1));
}

TEST(GraphTest, SameSizeInitializationTest) {
    int numbers[5] = { 1,2,3,4,5 };
    MatrixGraph<int> graph(numbers, 5, 5);

    std::string test = "Here is the adjacency matrix:\n"
        " id  0   1   2   3   4  \n"
        "  0  0   0   0   0   0  \n"
        "  1  0   0   0   0   0  \n"
        "  2  0   0   0   0   0  \n"
        "  3  0   0   0   0   0  \n"
        "  4  0   0   0   0   0  \n";

    EXPECT_EQ(graph.getSize(), 5);
    EXPECT_EQ(graph.displayGraph(), test);
}

TEST(GraphTest, NegativeArrayInitializationTest) {
    int numbers[5] = { 1,2,3,4,5 };
    MatrixGraph<int> graph(numbers, -1, 5);

    std::string test = "Here is the adjacency matrix:\n"
        " id \n";

    EXPECT_EQ(graph.getSize(), 0);
    EXPECT_EQ(graph.getMaxSize(), 5);
    EXPECT_EQ(graph.displayGraph(), test);
}

TEST(GraphTest, NegativeGraphInitializationTest) {
    int numbers[5] = { 1,2,3,4,5 };
    ASSERT_ANY_THROW(MatrixGraph<int> graph(numbers, 5, -1));
}

TEST(GraphTest, BothNegativeInitializationTest) {
    int numbers[5] = { 1,2,3,4,5 };
    ASSERT_ANY_THROW(MatrixGraph<int> graph(numbers, -1, -1));
}

TEST(GraphTest, BiggerGraphThanArrayInitializationTest) {
    int numbers[5] = { 1,2,3,4,5 };
    MatrixGraph<int> graph(numbers, 5, 7);

    std::string test = "Here is the adjacency matrix:\n"
        " id  0   1   2   3   4  \n"
        "  0  0   0   0   0   0  \n"
        "  1  0   0   0   0   0  \n"
        "  2  0   0   0   0   0  \n"
        "  3  0   0   0   0   0  \n"
        "  4  0   0   0   0   0  \n";

    EXPECT_EQ(graph.getSize(), 5);
    EXPECT_EQ(graph.displayGraph(), test);
}

TEST(GraphTest, SmallerGraphThanArrayInitializationTest) {
    int numbers[7] = { 1,2,3,4,5,6,7 };
    // graph will only insert the first 5 ints from the array.
    MatrixGraph<int> graph(numbers, 7, 5);

    std::string test = "Here is the adjacency matrix:\n"
        " id  0   1   2   3   4  \n"
        "  0  0   0   0   0   0  \n"
        "  1  0   0   0   0   0  \n"
        "  2  0   0   0   0   0  \n"
        "  3  0   0   0   0   0  \n"
        "  4  0   0   0   0   0  \n";

    EXPECT_EQ(graph.getSize(), 5);
    EXPECT_EQ(graph.displayGraph(), test);
}

TEST(GraphTest, ZeroGraphSizeInitializationTest) {
    int numbers[5] = { 1,2,3,4,5 };
    MatrixGraph<int> graph(numbers, 5, 0);

    std::string test = "Here is the adjacency matrix:\n"
        " id \n";

    EXPECT_EQ(graph.getSize(), 0);
    EXPECT_EQ(graph.displayGraph(), test);
}

TEST(GraphTest, GetNodeTest) {
    int numbers[5] = { 0,1,2,3,4 };
    MatrixGraph<int> graph(numbers, 5, 5);

    EXPECT_EQ(graph.getNode(0), 0);
    EXPECT_EQ(graph.getNode(1), 1);
    EXPECT_EQ(graph.getNode(2), 2);
    EXPECT_EQ(graph.getNode(3), 3);
    EXPECT_EQ(graph.getNode(4), 4);
}

TEST(GraphTest, BidirectionalEdgeTest) {
    int numbers[5] = { 0,1,2,3,4 };
    MatrixGraph<int> graph(numbers, 5, 5);

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

    EXPECT_EQ(graph.getSize(), 5);
    EXPECT_EQ(graph.displayGraph(), test);
}

TEST(GraphTest, IdenticalNodesTest) {
    int numbers[5] = { 0,0,0,0,0 };
    MatrixGraph<int> graph(numbers, 5, 5);

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

    EXPECT_EQ(graph.getSize(), 5);
    EXPECT_EQ(graph.displayGraph(), test);
}

TEST(GraphTest, AddVertexNoExpandTest) {
    int numbers[4] = { 0,1,2,3 };
    MatrixGraph<int> graph(numbers, 4, 5);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);

    EXPECT_EQ(graph.getSize(), 4);
    EXPECT_EQ(graph.getMaxSize(), 5);

    graph.addVertex(4);
    graph.addEdge(3, 4);

    std::string test = "Here is the adjacency matrix:\n"
        " id  0   1   2   3   4  \n"
        "  0  0   1   0   0   0  \n"
        "  1  1   0   1   0   0  \n"
        "  2  0   1   0   1   0  \n"
        "  3  0   0   1   0   1  \n"
        "  4  0   0   0   1   0  \n";

    EXPECT_EQ(graph.getSize(), 5);
    EXPECT_EQ(graph.getMaxSize(), 5);
    EXPECT_EQ(graph.getNode(4), 4);
    EXPECT_EQ(graph.displayGraph(), test);
}

TEST(GraphTest, AddVertexWithExpandTest) {
    int numbers[4] = { 0,1,2,3 };
    MatrixGraph<int> graph(numbers, 4, 4);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);

    EXPECT_EQ(graph.getSize(), 4);
    EXPECT_EQ(graph.getMaxSize(), 4);

    graph.addVertex(4);
    graph.addEdge(3, 4);


    std::string test = "Here is the adjacency matrix:\n"
        " id  0   1   2   3   4  \n"
        "  0  0   1   0   0   0  \n"
        "  1  1   0   1   0   0  \n"
        "  2  0   1   0   1   0  \n"
        "  3  0   0   1   0   1  \n"
        "  4  0   0   0   1   0  \n";

    EXPECT_EQ(graph.getSize(), 5);
    EXPECT_EQ(graph.getMaxSize(), 6); // 4 * 1.5 = 6
    EXPECT_EQ(graph.getNode(4), 4);
    EXPECT_EQ(graph.displayGraph(), test);
}

TEST(GraphTest, AddVertexExpandFromZeroTest) {
    int numbers[4] = { 0,1,2,3 };
    MatrixGraph<int> graph(numbers, 4, 0);

    EXPECT_EQ(graph.getSize(), 0);
    EXPECT_EQ(graph.getMaxSize(), 0);

    graph.addVertex(10);

    std::string test = "Here is the adjacency matrix:\n"
        " id  0  \n"
        "  0  0  \n";

    EXPECT_EQ(graph.getSize(), 1);
    EXPECT_EQ(graph.getMaxSize(), 2);
    EXPECT_EQ(graph.getNode(0), 10);
    EXPECT_EQ(graph.displayGraph(), test);
}

TEST(GraphTest, AddVertexExpandFromOneTest) {
    int numbers[4] = { 0,1,2,3 };
    MatrixGraph<int> graph(numbers, 4, 1);

    EXPECT_EQ(graph.getSize(), 1);
    EXPECT_EQ(graph.getMaxSize(), 1);

    graph.addVertex(10);

    std::string test = "Here is the adjacency matrix:\n"
        " id  0   1  \n"
        "  0  0   0  \n"
        "  1  0   0  \n";

    EXPECT_EQ(graph.getSize(), 2);
    EXPECT_EQ(graph.getMaxSize(), 2);
    EXPECT_EQ(graph.getNode(0), 0);
    EXPECT_EQ(graph.getNode(1), 10);
    EXPECT_EQ(graph.displayGraph(), test);
}

TEST(GraphTest, ClearGraphTest) {
    int numbers[4] = { 0,1,2,3 };
    MatrixGraph<int> graph(numbers, 4, 4);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);

    graph.clear();

    std::string test = "Here is the adjacency matrix:\n"
        " id \n";

    EXPECT_EQ(graph.displayGraph(), test);

    graph.addVertex(4);
    graph.addVertex(5);
    graph.addVertex(6);
    graph.addVertex(7);
    graph.addVertex(8);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    test = "Here is the adjacency matrix:\n"
        " id  0   1   2   3   4  \n"
        "  0  0   1   0   0   0  \n"
        "  1  1   0   1   0   0  \n"
        "  2  0   1   0   1   0  \n"
        "  3  0   0   1   0   1  \n"
        "  4  0   0   0   1   0  \n";

    EXPECT_EQ(graph.getSize(), 5);
    EXPECT_EQ(graph.getNode(0), 4);
    EXPECT_EQ(graph.getNode(4), 8);
    EXPECT_EQ(graph.displayGraph(), test);
}

TEST(GraphTest, ClearEmptyGraphTest) {
    MatrixGraph<int> graph;
    graph.clear();

    std::string test = "Here is the adjacency matrix:\n"
        " id \n";

    EXPECT_EQ(graph.displayGraph(), test);

    graph.addVertex(4);
    graph.addVertex(5);
    graph.addVertex(6);
    graph.addVertex(7);
    graph.addVertex(8);

    test = "Here is the adjacency matrix:\n"
        " id  0   1   2   3   4  \n"
        "  0  0   0   0   0   0  \n"
        "  1  0   0   0   0   0  \n"
        "  2  0   0   0   0   0  \n"
        "  3  0   0   0   0   0  \n"
        "  4  0   0   0   0   0  \n";

    EXPECT_EQ(graph.getSize(), 5);
    EXPECT_EQ(graph.getNode(0), 4);
    EXPECT_EQ(graph.getNode(4), 8);
    EXPECT_EQ(graph.displayGraph(), test);
}

#endif //GRAPH_TEST_HPP