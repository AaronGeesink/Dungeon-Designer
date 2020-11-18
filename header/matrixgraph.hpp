// C++ implementation of a graph using an adjacency matrix
#include <vector> 
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

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
	int numEdges;	/// Number of edges
	int** adj;	/// Adjacency matrix
	Vertex<T>* vertices;	/// Vertices of the graph
	vector<pair<double,pair<int, int>>> edges;	/// ids for the graph's edges

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
	 * @brief addEdge(T start, T end, double weight)
	 * Function to insert a new edge
	 * @param T start, T end, double weight
	 */
    void addEdge(T start, T end, double weight);

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

	/**
	 * @author Aaron Geesink
	 * @brief clear()
	 * function to clear the graph of all of it's data.
	 */
	void clear();

	/**
	 * @author Aaron Geesink
	 * @brief displayGraph()
	 * Function to display the adjacency matrix for the graph
	 */
	void displayGraph();
};

// Function to fill the empty adjacency matrix
template <typename T>
MatrixGraph<T>::MatrixGraph(T elements[], int size)
{
    this->numVertices = size;
    vertices = new Vertex<T>[size];
    adj = new int*[numVertices];
    for (int row = 0; row < numVertices; row++)
    {
        adj[row] = new int[numVertices];
        vertices[row].value = elements[row];
        vertices[row].id = row;
        for (int column = 0; column < numVertices; column++)
        {
            adj[row][column] = 0;
        }
	}
}

template<typename T>
MatrixGraph<T>::~MatrixGraph()
{
	for (int i = 0; i < numVertices; i++)
	{
		delete [] adj[i];
	}

	delete [] vertices;
	delete [] edges;

	numVertices = 0;
	numEdges = 0;
}

template<typename T>
inline void MatrixGraph<T>::clear()
{
	for (int i = 0; i < numVertices; i++)
	{
		delete [] adj[i];
	}

	delete [] vertices;
	delete [] edges;

	numVertices = 0;
	numEdges = 0;
};

// Function to add an edge to the MatrixGraph
template <typename T>
void MatrixGraph<T>::addEdge(T start, T end, double weight)
{
    int startID = 0;
    int endID = 0;

    for (int i = 0; i < numVertices; i++)
    {
        if (start == vertices[i].value)
        {
            startID = i;
        }
        if (end == vertices[i].value)
        {
            endID = i;
        }
    }
    // Considering a bidirectional edge
    adj[startID][endID] = 1;
	//adj[endID][startID] = 1;

    Edge<T> edgeForward = { start, end, weight };
	//Edge<T> edgeBackward = { end, start, weight };

    vertices[startID].edges.push_back(edgeForward);
	//vertices[endID].edges.push_back(edgeBackward);

    edges.push_back(make_pair( weight, make_pair(startID, endID)));

    vertices[startID].edges.back().pEndVertex = &vertices[endID];
	//vertices[endID].edges.back().pEndVertex = &vertices[startID];

    vertices[startID].edges.back().pStartVertex = &vertices[startID];
	//vertices[endID].edges.back().pStartVertex = &vertices[endID];
}

template<typename T>
inline std::vector<Edge<T>> MatrixGraph<T>::DFS(T start)
{
    // set start and end time to -1 for the edge comparisons
    for (int i = 0; i < numVertices; i++)
    {
        vertices->startTime = -1;
        vertices->endTime = -1;
    }

    vector<bool> visited(numVertices, false); // vector to check if a vertex is visited
    std::vector<Edge<T>> discoveryEdges;	// vector of the DFS discovery edges

    //cout << "Here is the adjacency list:\n";
    DFSDriver(start, visited, discoveryEdges);

    return discoveryEdges;
}

template<typename T>
inline void MatrixGraph<T>::DFSDriver(T start, vector<bool> &visited, std::vector<Edge<T>>& discoveryEdges, int counter)
{
    int dTotal = 0;
    int id = 0;

    // Set the current city to visited and track its startTime
    for (int i = 0; i < numVertices; i++)
    {
        if (vertices[i].value == start)
        {
            visited[i] = true;
            vertices[i].startTime = counter;
            id = i;
        }
    }

    // sort the current vertex's edges in order of increasing weight
    sort(vertices[id].edges.begin(), vertices[id].edges.end(), compareEdgeWeight<T>());

    // copy edges
    vector<Edge<T>> edges;
    for (auto it = vertices[id].edges.begin(); it != vertices[id].edges.end(); it++)
    {
        edges.push_back(*it);
    }
    for (int i = 0; i < edges.size(); i++)
        {
        // Get all discovery edges
        if (!visited[edges[i].pEndVertex->id])
        {
            discoveryEdges.push_back(edges[i]);
            /*
            cout << "Discovery: " << it->start << " --> " << it->end
                << " (" << it->weight << ")\n";
            */

            counter++;
            DFSDriver(edges[i].pEndVertex->value, visited, discoveryEdges, counter);
            counter++;
            edges[i].pEndVertex->endTime = counter;
            dTotal += edges[i].weight;
        }
        /*
        // Get all back edges
        else if (it->pEndVertex->endTime == -1)
        {
            cout << "Back: " << it->start << " --> " << it->end
                << " (" << it->weight << ")\n";
        }
        // Get all forward edges
        else if (it->pEndVertex->endTime != -1 && it->pEndVertex->endTime > counter)
        {
            cout << "Forward: " << it->start << " --> " << it->end
                << " (" << it->weight << ")\n";
        }
        // Get cross edges
        else
        {
            cout << "Cross: " << it->start << " --> " << it->end
                << " (" << it->weight << ")\n";
        }
        */
    }
}

// Function to perform BFS on the MatrixGraph
template <typename T>
std::vector<Edge<T>> MatrixGraph<T>::BFS(T start)
{
    int dTotal = 0;
    std::vector<Edge<T>> discoveryEdges;

    // Visited vector to so that
    // a vertex is not visited more than once
    // Initializing the vector to false as no
    // vertex is visited at the beginning
    vector<bool> visited(numVertices, false);
    vector<int> q;
    int current;	// index location of current vertex

    // find starting index location
    int id = 0;
    for (int i = 0; i < numVertices; i++)
    {
        if (start == vertices[i].value)
        {
            vertices[i].depth = 0;
            id = i;
        }
    }

    q.push_back(id);

    // Set source as visited
    visited[id] = true;

    while (!q.empty())
    {
        current = q[0];

        for (int i = 0; i < numVertices; i++)
        {
            if (vertices[current].value == vertices[i].value)
            {
                id = i;
            }
        }

        // sort the current vertex's edges in order of increasing weight
        sort(vertices[current].edges.begin(), vertices[current].edges.end(), compareEdgeWeight<T>());

        // Print the current node
        q.erase(q.begin());

        int numVisited = 0;
        // For every adjacent vertex to the current vertex
        //for (auto it = vertices[current].edges.begin(); it != vertices[current].edges.end(); it++)
        for (int i = 0; i < vertices[current].edges.size(); i++)
        {
            if (!visited[vertices[current].edges[i].pEndVertex->id])
            {
                // Push the adjacent node to the queue
                q.push_back(vertices[current].edges[i].pEndVertex->id);

                // Set that node to be visited
                visited[vertices[current].edges[i].pEndVertex->id] = true;

                // set parent vertex
                vertices[vertices[current].edges[i].pEndVertex->id].parent = &vertices[current];

                // assign the vertex a depth for edge comparison
                vertices[current].edges[i].pEndVertex->depth = vertices[current].depth + 1;

                // add to discovery distance
                dTotal += vertices[current].edges[i].weight;
                /*
                cout << "Discovery: " << it->start << " --> " << it->end
                    << " (" << it->weight << ")\n";
                */
                discoveryEdges.push_back(vertices[current].edges[i]);
                numVisited = numVisited + 1;
            }
            /*
            else if (visited[it->pEndVertex->id])
            {
                Vertex<T>* startVertex = &vertices[current];
                Vertex<T>* endVertex = it->pEndVertex;

                // go up parents until both vertices are at same depth
                while (startVertex->depth > endVertex->depth)
                {
                    startVertex = startVertex->parent;
                }
                while (endVertex->depth > startVertex->depth)
                {
                    endVertex = endVertex->parent;
                }

                // if the vertices are the same, its a back edge
                if (startVertex->value == endVertex->value)
                {
                    cout << "Back Edge: " << it->start << " --> " << it->end
                        << " (" << it->weight << ")\n";
                }
                // if the vertices are not the same, its a cross edge
                else
                {
                    cout << "Cross Edge: " << it->start << " --> " << it->end
                        << " (" << it->weight << ")\n";
                }

                numVisited = numVisited + 1;
            }
            */
        }
    }

    //cout << "\nTotal distance traveled over discovery edges: " << dTotal << '\n';
    return discoveryEdges;
}

template<typename T>
std::vector<Vertex<T>> MatrixGraph<T>::aStar(T start, T target)
{
    /*
    if (start == target)
    {
        cout << start << " --> " << target << ":\n\t"
            << start << " (0) = 0\n\n";
        return discoveryEdges;
    }
    */

    vector<Vertex<T>> open;	// list of vertices set to be checked
    vector<Vertex<T>> closed;	// list of vertices already checked
    vector<Vertex<T>> path;	// vertices of the final path after target is found
    int startID;	// index of starting vertex

    for (int i = 0; i < numVertices; i++)
    {        if (vertices[i].value == start)
            startID = i;
    }
    Vertex<T> currentNode = vertices[startID];
    do
     {
         sort(vertices[currentNode.id].edges.begin(), vertices[currentNode.id].edges.end(), compareEdgeWeight<T>());

         closed.push_back(currentNode);
         for (int i = 0; i < currentNode.edges.size(); i++)
         {
             open.push_back(*currentNode.edges[i].pEndVertex);
             open[open.size() - 1].cost = currentNode.cost + currentNode.edges[i].weight;
             open[open.size() - 1].parent = new Vertex<T>(currentNode);
         }
         for (int i = 0; i < closed.size(); i++)
         {
             for (int j = 0; j < open.size(); j++)
             {
                 if (closed[i].value == open[j].value)
                 {
                     open.erase(open.begin() + j);
                     j--;
                 }
             }
         }
         currentNode = open[0];
         for (int i = 1; i < open.size(); i++)
         {
             if (open[i].cost < currentNode.cost)
             {
                 currentNode = open[i];
             }
         }
     } while (currentNode.value != target);

    // push the calculated path to the path vector
    path.push_back(currentNode);
    while (path[path.size() - 1].value != start)
    {
        path.push_back(*path[path.size() - 1].parent);
    }

    return path;

    int totalDistance = 0;
/*
    // display the A* path
    cout << start << " --> " << target << ": \n\t"
        << path[path.size() - 1].value;

    for (int i = path.size() - 2; i >= 0; i--)
    {
        for (int j = 0; j < path[i].edges.size(); j++)
        {
            if (path[i].edges[j].pEndVertex->value == path[i].parent->value)
            {
                cout << " --> " << path[i].value << " (" << path[i].edges[j].weight << ")";
                totalDistance += path[i].edges[j].weight;
            }
        }
    }

    cout << " = " << totalDistance << "\n\n";
*/
}

template<typename T>
inline void MatrixGraph<T>::displayGraph()
{
    cout << "Here is the adjacency matrix:\n";
    cout << "    ";
    for (int i = 0; i < numVertices; i++)
    {
        cout << vertices[i].value.substr(0, 3) << " ";
    }
    cout << endl;
    for (int row = 0; row < numVertices; row++)
    {
        for (int col = 0; col < numVertices + 1; col++)
        {
            if (col == 0)
                cout << vertices[row].value.substr(0, 3);
            else
            {
                cout << " " << adj[row][col - 1] << " ";
            }
            cout << " ";
        }
        cout << endl;
    }
}

struct DisjointSets
{
    int *parent, *rnk;
    int n;

    DisjointSets(int n)
    {
        this->n = n;
        parent = new int[n + 1];        rnk = new int[n + 1];
        for (int i = 0; i <= n; i++)
        {
            rnk[i] = 0;
            parent[i] = i;
        }
    }
    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
    void merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (rnk[x] > rnk[y])
            parent[y] = x;
        else
            parent[x] = y;
        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};

template<typename T>
inline std::vector<Edge<T>> MatrixGraph<T>::kruskalMST()
{
    std::vector<Edge<T>> discoveryEdges;

    double totalWeight = 0;
    sort(edges.begin(), edges.end());
    DisjointSets ds(numVertices);
	vector< pair<double, pair<int, int> > >::iterator it;

    for (it = edges.begin(); it != edges.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

        if (set_u != set_v)
        {
            // Current edge will be in the MST
            // so add it to discovery edges
            // cout << vertices[u].value << " -- " << vertices[v].value << ": " << it->first << endl;

            Edge<T> edge = { vertices[u].value, vertices[v].value, it->first };
            discoveryEdges.push_back(edge);

            // Update MST weight
            totalWeight += it->first;

            // Merge two sets
            ds.merge(set_u, set_v);
        }
    }

	return discoveryEdges;
}