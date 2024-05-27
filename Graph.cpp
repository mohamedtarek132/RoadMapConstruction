#include "Graph.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
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
// to use it with the sort function
bool Edge::	comparetor(Edge edge1, Edge edge2)
{
    return edge1.length < edge2.length;
}
// to use it with the set data structure
bool Edge::	operator < (Edge e) const
{
    return ((vertex1 + vertex2) < (e.getVertex1() + e.getVertex2()));
}

// to use it with the set data structure
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
    adjacencyList[vertex] = list<Edge>();
    positions[vertex] = make_pair(x, y);
}

void Graph::insertEdge(string vertex_1, string vertex_2, double length)
{
    // to add an edge in the list of each vertex
    adjacencyList[vertex_1].push_back(Edge(vertex_1, vertex_2, length));
    adjacencyList[vertex_2].push_back(Edge(vertex_2, vertex_1, length));
}

void Graph::deleteVertex(string vertex)
{
    // to delete the edges in other verticies list
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
}
queue<Edge> Graph::BFStraversal(string first_node)
{
    queue<string> nodes;
    nodes.push(first_node);
    queue<Edge> edgeOrder;

    unordered_map<string, bool> visited;
    visited[first_node] = true;

    while (!nodes.empty())
    {
        string node = nodes.front();
        nodes.pop();

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
    stack<string> vertexStack;
    stack<Edge> edgeStack;

    queue<Edge> edgeOrder;

    string currentVertex = first_node;
    Edge currentEdge;

    vertexStack.push(currentVertex);

    while (!vertexStack.empty())
    {
        currentVertex = vertexStack.top();
        vertexStack.pop();

        if(!edgeStack.empty())
        {
            currentEdge = edgeStack.top();
            edgeStack.pop();
        }

        if (!visited[currentVertex])
        {
            visited[currentVertex] = true;

            if(!edgeStack.empty())
            {
                edgeOrder.push(currentEdge);
            }
        }
        else
        {
            continue;
        }

        for (auto it = adjacencyList[currentVertex].begin(); it != adjacencyList[currentVertex].end(); it++)
        {
            if (!visited[it->getVertex2()])
            {
                vertexStack.push(it->getVertex2());
                edgeStack.push(*it);
            }
        }
    }

    return edgeOrder;
}

queue<Edge> Graph::DijkstraShortestPath(string start, string end)
{
    queue<Edge> edgeOrder;

    unordered_map<string, bool> visitedVerticies;

    unordered_map<string, Edge> predecessors;

    unordered_map<string, int> weight;

    for(auto i = adjacencyList.begin(); i != adjacencyList.end(); i++)
    {
        weight[i->first] = INT_MAX;
    }

    int size = adjacencyList.size();

    weight[end] = 0;

    visitedVerticies[end] = true;

    string currentVertex = end;
    while(size--)
    {
        int smallestEdge = INT_MAX;
        // to get the smallest current weight vertex
        auto it = min_element(weight.begin(), weight.end(), [](const auto& l, const auto& r) { return l.second < r.second; });

        visitedVerticies[it->first] = true;
        currentVertex = it->first;

        int currentWeight = weight[currentVertex];

        weight.erase(currentVertex);

        if(currentVertex.size() != 0)
        {
            for(auto i = adjacencyList[currentVertex].begin(); i!= adjacencyList[currentVertex].end(); i++)
            {
                int newWeight = i->length + currentWeight;
                string adjacentVertex = i->getVertex2();

                if(!visitedVerticies[adjacentVertex] && (newWeight < weight[adjacentVertex]))
                {
                    weight[adjacentVertex] = newWeight;
                    predecessors[adjacentVertex] = *i;
                }
            }
        }
    }

    currentVertex = start;
    int counter = 0;

    while(currentVertex != end && counter!= adjacencyList.size())
    {
        string vertex1 = predecessors[currentVertex].getVertex1();
        edgeOrder.push(predecessors[currentVertex]);
        currentVertex = vertex1;
    }

    return edgeOrder;
}

queue<Edge> Graph::unconnectedTraversal()
{
    set<Edge> trying;
    for(auto it = adjacencyList.begin(); it != adjacencyList.end(); it++)
    {
        queue<Edge> edge = BFStraversal(it->first);
        while(!edge.empty())
        {
            trying.insert(edge.front());
            edge.pop();
        }
    }
    queue<Edge>edges;
    for(auto it = trying.begin(); it != trying.end(); it++)
    {
        edges.push(*it);
    }
    return edges;
}
