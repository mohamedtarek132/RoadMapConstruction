#include "Graph.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>

Edge::Edge(string vertex1, string vertex2, double length)
{
    this->vertex1 = vertex1;
    this->vertex2 = vertex2;
    this->length = length;
}
Edge::Edge()
{
    this->vertex1 = "";
    this->vertex2 = "";
    this->length = 0;
}
bool Edge::	comparetor(Edge edge1, Edge edge2)
{
    return edge1.length < edge2.length;
}
bool Edge::	operator < (Edge e) const
{
    return ((vertex1 + vertex2) < (e.getVertex1() + e.getVertex2()));
}
bool Edge::operator == (Edge e)
{
    return vertex1 == e.getVertex1() && vertex2 == e.getVertex2();
}

string Edge::getVertex1()
{
    return vertex1;
}
string Edge::getVertex2()
{
    return vertex2;
}

void Graph::insertVertex(string vertex, int x, int y)
{
    adjacencyList.insert(make_pair(vertex, list<Edge>()));
    positions[vertex] = make_pair(x, y);
}
void Graph::insertEdge(string vertex_1, string vertex_2, double length)
{
    adjacencyList[vertex_1].push_back(Edge(vertex_1, vertex_2, length));
    adjacencyList[vertex_2].push_back(Edge(vertex_2, vertex_1, length));
}
void Graph::deleteVertex(string vertex)
{
    for (auto i = adjacencyList[vertex].begin(); i != adjacencyList[vertex].end(); i++)
    {
        deleteEdge(i->getVertex1(), i->getVertex2());
    }
    adjacencyList.erase(vertex);
    positions.erase(vertex);
}
void Graph::deleteEdge(string vertex_1, string vertex_2)
{
    for (auto i = adjacencyList[vertex_1].begin(); i != adjacencyList[vertex_1].end(); i++)
    {
        if ((i->getVertex1() == vertex_1 && i->getVertex2() == vertex_2))
        {
            adjacencyList[vertex_1].erase(i);
        }
    }

    for (auto i = adjacencyList[vertex_2].begin(); i != adjacencyList[vertex_2].end(); i++)
    {
        if ((i->getVertex1() == vertex_2 && i->getVertex2() == vertex_1))
        {
            adjacencyList[vertex_2].erase(i);
        }
    }
}

queue<Edge> Graph::PrimMinimumSpanningTree(string vertex)
{
    ///
    /// kjljl
    /// lklk
    ///
    /// klklk
    ///
    unordered_map<string,bool> visitedVerticies;

    queue<Edge> edgesOrder;

    vector<Edge> unusedAdjacentEdges;

    string currentNode = vertex;

    int counter = adjacencyList.size();

    visitedVerticies[currentNode] = true;

    while (counter--)
    {
        for (auto i = adjacencyList[currentNode].begin(); i != adjacencyList[currentNode].end(); i++)
        {
            unusedAdjacentEdges.push_back(*i);
        }

        sort(unusedAdjacentEdges.begin(), unusedAdjacentEdges.end(), Edge::comparetor);

        bool makeCycle = true;

        while (makeCycle && !unusedAdjacentEdges.empty())
        {

            Edge currentEdge = unusedAdjacentEdges[0];

            bool foundVertex = visitedVerticies[currentEdge.getVertex2()];

            if (!foundVertex)
            {
                edgesOrder.push(currentEdge);

                currentNode = currentEdge.getVertex2();

                visitedVerticies[currentNode] = true;

                makeCycle = false;
            }

            unusedAdjacentEdges.erase(unusedAdjacentEdges.begin());
        }
    }

    int size = edgesOrder.size();

    return edgesOrder;

    // for (int i = 0; i < size; i++)
    // {
    //     cout << edgesOrder.front().getVertex1() << " " << edgesOrder.front().getVertex2() <<
    //         " " << edgesOrder.front().length << endl;
    //     edgesOrder.pop();
    // }
}
queue<Edge> Graph::BFStraversal(string first_node)
{
    // insertVertex("a");
    // insertVertex("b");
    // insertVertex("c");
    // insertVertex("d");
    // insertVertex("e");
    // insertVertex("f");

    // insertEdge("a", "b", 4);
    // insertEdge("a", "c", 4);
    // insertEdge("b", "c", 2);
    // insertEdge("c", "d", 3);
    // insertEdge("c", "e", 2);
    // insertEdge("c", "f", 4);
    // insertEdge("d", "f", 3);
    // insertEdge("e", "f", 3);

    queue<string> nodes;
    nodes.push(first_node);
    queue<Edge> edgeOrder;

    unordered_map<string, bool> visited;
    visited[first_node] = true;

    while (!nodes.empty())
    {
        string node = nodes.front();
        // cout << node << endl;
        nodes.pop();
        // visited[node] = true;
        for (auto i = adjacencyList[node].begin(); i != adjacencyList[node].end(); i++)
        {
            if (!visited[i->getVertex2()])
            {
                nodes.push(i->getVertex2());
                visited[i->getVertex2()] = true;
                edgeOrder.push(*i);
            }
        }
    }
    return edgeOrder;
}

queue<Edge> Graph::DFStraversal(string first_node) {

    unordered_map<string,bool> visited;
    stack<string> edgeStack;
    queue<Edge> edgeOrder;

    string current = first_node;
    edgeStack.push(current);

    while (!edgeStack.empty())
    {
        current = edgeStack.top();
        edgeStack.pop();


        if (!visited[current])
        {
            visited[current] = true;
        }

        for (auto it = adjacencyList[current].begin(); it != adjacencyList[current].end(); it++)
        {
            if (!visited[it->getVertex2()])
            {
                edgeStack.push(it->getVertex2());
                edgeOrder.push(*it);
            }
        }
    }

    return edgeOrder;
}

queue<Edge> DijkstraShortestPath(string start, string end)
{
    queue<Edge> edgeOrder;

    return edgeOrder;
}
