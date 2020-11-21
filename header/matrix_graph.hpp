// C++ implementation of a graph using an adjacency matrix
#include <string>
#include <vector> 
#include <list>
#include <algorithm>
#include <utility>
using std::make_pair;
using std::vector;

template <typename T>
struct Vertex;

/**
 *@author Aaron Geesink
 *@brief Edge struct
 * A struct which contains a single edge on the graph
 *@date December 2019
 */
template <typename T>
struct Edge
{
    //TODO: REPLACE T start and T end with int indexStart and int indexEnd
	T start;
	T end;
    double weight;
	Vertex<T>* pEndVertex;
	Vertex<T>* pStartVertex;
};

/**
 *@author Aaron Geesink
 *@brief compareEdgeWeight struct
 * Comparator functor to compare weights of 2 edges
 *@date December 2019
 */
template <typename T>
struct compareEdgeWeight
{
	bool operator()(const Edge<T> & e1, const Edge<T> & e2) const
	{
        if (e1.weight < e2.weight)
			return true;
        if (e2.weight < e1.weight)
			return false;
		return true;
	}
};

/**
 *@author Aaron Geesink
 *@brief Vertex struct
 * A struct which contains a vertex edge on the graph
 *@date December 2019
 */
template <typename T>
struct Vertex
{
	T value;	/// data stored in the vertex
	vector<Edge<T>> edges;	/// edges of the vertex
	Vertex<T>* parent;	/// pointer to parent vertex in current traversal
	int id;		/// id for easy retrieval
	int startTime = -1;		/// start time for determining DFS edges
	int endTime = -1;	/// end timefor determining DFS edges
	int depth;	/// depth for determining BFS edge
	int cost;	/// cost for A-Star Pathfinding
};

/**
 *@author Aaron & Garrett Geesink
 *@brief MatrixGraph class
 * This is the graph class used to instantiate and perform traversals on graphs
 *@date December 2019
 */
template <typename T>
class MatrixGraph 
{
private:
	int numVertices;	/// Number of vertex
	int** adj;	/// Adjacency matrix
	Vertex<T>* vertices;	/// Vertices of the graph
	vector<std::pair<double,std::pair<int, int>>> edges;	/// ids for the graph's edges

	// Driver Function to calculate the depth first search traversal
	void DFSDriver(T start, vector<bool> &visited, std::vector<Edge<T>>& discoveryEdges, int counter = 0);

public:
	/**
	 * @author Aaron Geesink
	 * @brief MatrixGraph(T elements[], int size)
	 * Constructor to create the initial adjacency matrix
	 * @param T elements[], int size
	 */
    MatrixGraph(T elements[], int size);

	/**
	 * @author Aaron Geesink
	 * @brief ~MatrixGraph()
	 * deconstructor for a graph
	 */
	~MatrixGraph();

    /**
     * @author Aaron Geesink
     * @brief displayGraph()
     * Function to return the number of nodes in the graph.
     */
    int size() { return numVertices; }

    /**
     * @author Aaron Geesink
     * @brief clear()
     * function to clear the graph of all of it's data.
     */
    void clear();

	/**
	 * @author Aaron Geesink
	 * @brief addEdge(T start, T end, double weight)
	 * Function to insert a new edge
	 * @param T start, T end, double weight
	 */
    void addEdge(int startIndex, int endIndex, double weight = 1);

    /**
     * @author Aaron Geesink
     * @brief addVertex(T vertex)
     * function to expand the graph by 1 and insert a new edge
     */
    void addVertex(T vertex);

    /**
     * @author Aaron Geesink
     * @brief getNode(in index)
     * Function to return a node object in the graph.
     * Index locations start at 0.
     */
    T getNode(int index);

    /**
     * @author Aaron Geesink
     * @brief displayGraph()
     * Function to display the adjacency matrix for the graph.
     */
    std::string displayGraph();

	/**
	 * @author Aaron & Garrett Geesink
	 * @brief DFS(T start)
	 * function to call DFS from the client
	 * @param T start
	 * @return std::vector<Edge<T>>
	 */
	std::vector<Edge<T>> DFS(T start);

	/**
	 * @author Aaron Geesink
	 * @brief BFS(T start)
	 * Function to calculate the breadth first search traversal
	 * @param T start
	 * @return std::vector<Edge<T>>
	 */
	std::vector<Edge<T>> BFS(T start);

	/**
	 * @author Aaron & Garrett Geesink
	 * @brief aStar(T start, T target)
	 * Function to calculate the aStar path from start to target
	 * @param T start, T target
	 * @return std::vector<Vertex<T>>
	 */
	std::vector<Vertex<T>> aStar(T start, T target);

	/**
	 * @author Aaron Geesink
	 * @brief kruskalMST()
	 * Function to calculate the minimum spanning tree using Kruskal's algorithm
	 * @return std::vector<Edge<T>>
	 */
	std::vector<Edge<T>> kruskalMST();
};