#ifndef MATRIX_GRAPH_CPP
#define MATRIX_GRAPH_CPP

#include "../header/matrix_graph.hpp"

#include <iomanip>
#include <sstream>
#include "center_helper.hpp"

using std::vector;
using std::string;

// Constructor to fill the empty adjacency matrix
template <typename T>
MatrixGraph<T>::MatrixGraph(T elements[], int size)
{
    this->numVertices = size;
    vertices = new Vertex<T>[size];
    adj = new int* [numVertices];
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

// Destructor
template<typename T>
MatrixGraph<T>::~MatrixGraph()
{
    for (int i = 0; i < numVertices; i++)
    {
        delete[] adj[i];
    }
    delete[] adj;

    delete[] vertices;

    numVertices = 0;
}

// function to clear the graph of data and reinitialize it with size 0.
template<typename T>
void MatrixGraph<T>::clear()
{
    for (int i = 0; i < numVertices; i++)
    {
        delete[] adj[i];
    }
    delete[] adj;
    delete[] vertices;

    this->adj = new int* [0];
    this->vertices = new Vertex<T>[0];

    numVertices = 0;
};

// Function to add an edge to the MatrixGraph using index locations
template <typename T>
void MatrixGraph<T>::addEdge(int startIndex, int endIndex, double weight)
{
    // Considering a bidirectional edge
    adj[startIndex][endIndex] = 1;
    adj[endIndex][startIndex] = 1;

    // TODO: remove T start and T end from the Edge class, replace vertices[start/endIndex].value with just start/endIndex
    Edge<T> edgeForward = { vertices[startIndex].value, vertices[endIndex].value, weight };
    Edge<T> edgeBackward = { vertices[endIndex].value, vertices[startIndex].value, weight };

    vertices[startIndex].edges.push_back(edgeForward);
    vertices[endIndex].edges.push_back(edgeBackward);

    edges.push_back(make_pair(weight, make_pair(startIndex, endIndex)));
    edges.push_back(make_pair(weight, make_pair(endIndex, startIndex)));

    vertices[startIndex].edges.back().pEndVertex = &vertices[endIndex];
    vertices[endIndex].edges.back().pEndVertex = &vertices[startIndex];

    vertices[startIndex].edges.back().pStartVertex = &vertices[startIndex];
    vertices[endIndex].edges.back().pStartVertex = &vertices[endIndex];
}

// Function to expand the graph size by 1 and add a new vertex.
template <typename T>
void MatrixGraph<T>::addVertex(T newVertex)
{
    //Set up the data for the expanded graph
    int newSize = numVertices + 1;
    Vertex<T>* vertexTemp = new Vertex<T>[newSize];
    int** adjTemp = new int* [newSize];

    //First, copy over the existing vertices and edges
    for (int row = 0; row < numVertices; row++)
    {
        adjTemp[row] = new int[newSize];
        vertexTemp[row].value = vertices[row].value;
        vertexTemp[row].id = row;
        for (int column = 0; column < numVertices; column++)
        {
            adjTemp[row][column] = adj[row][column];
        }
    }

    //Second, initialize the new vertex
    adjTemp[newSize - 1] = new int[newSize];
    vertexTemp[newSize - 1].value = newVertex;
    vertexTemp[newSize - 1].id = newSize - 1;
    for (int index = 0; index < newSize; index++)
    {
        adjTemp[index][newSize - 1] = 0;
        adjTemp[newSize - 1][index] = 0;
    }

    //Third, delete the old data and transfer data from temp to the class data members
    for (int i = 0; i < numVertices; i++)
    {
        delete[] adj[i];
    }
    delete[] adj;
    delete[] vertices;

    this->adj = adjTemp;
    this->vertices = vertexTemp;
    this->numVertices = newSize;
}

template<typename T>
T MatrixGraph<T>::getNode(int index)
{
    return vertices[index].value;
}

template<typename T>
std::string MatrixGraph<T>::displayGraph()
{
    std::stringstream rtn;

    rtn << "Here is the adjacency matrix:\n";
    rtn << " id ";
    for (int i = 0; i < numVertices; i++)
    {
        rtn << std::setw(3) << centered(std::to_string(vertices[i].id)) << " ";
    }
    rtn << std::endl;
    for (int row = 0; row < numVertices; row++)
    {
        for (int col = 0; col < numVertices + 1; col++)
        {
            if (col == 0)
                rtn << std::setw(3) << vertices[row].id;
            else
            {
                rtn << " " << adj[row][col - 1] << " ";
            }
            rtn << " ";
        }
        rtn << std::endl;
    }
    return rtn.str();
}

template<typename T>
std::vector<Edge<T>> MatrixGraph<T>::DFS(T start)
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
void MatrixGraph<T>::DFSDriver(T start, vector<bool>& visited, std::vector<Edge<T>>& discoveryEdges, int counter)
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
    {
        if (vertices[i].value == start)
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

struct DisjointSets
{
    int* parent, * rnk;
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
std::vector<Edge<T>> MatrixGraph<T>::kruskalMST()
{
    std::vector<Edge<T>> discoveryEdges;

    double totalWeight = 0;
    sort(edges.begin(), edges.end());
    DisjointSets ds(numVertices);
    vector< std::pair<double, std::pair<int, int> > >::iterator it;

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
            // cout << vertices[u].value << " -- " << vertices[v].value << ": " << it->first << std::endl;

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

#endif // MATRIX_GRAPH_CPP