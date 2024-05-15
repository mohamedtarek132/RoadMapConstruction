#ifndef GRAPH_H
#define GRAPH_H

#pragma once
#include <unordered_map>
#include <list>
#include <string>
#include <queue>
using namespace std;

class Edge
{
    string vertex1, vertex2;
public:
    Edge(string, string, double);
    Edge();
    double length;

    string getVertex1();
    string getVertex2();

    bool operator < (Edge e);
    bool operator < (Edge e) const;
    bool operator == (Edge e);
    static bool comparetor (Edge edge1, Edge edge2);
};

class Graph
{
public:

    unordered_map<string, list<Edge>> adjacencyList;
    unordered_map<string, pair<int, int>> positions;

    void insertVertex(string, int, int);
    void insertEdge(string, string, double);
    void deleteVertex(string);
    void deleteEdge(string, string);
    queue<Edge> DFStraversal(string);
    queue<Edge> BFStraversal(string);
    queue<Edge> PrimMinimumSpanningTree(string);
    queue<Edge> DijkstraShortestPath(string, string);
    queue<Edge> unconnectedTraversal();
};


#endif // GRAPH_H
