#pragma once 

#include <iostream>

#define MAXVERTEXS 5

struct edge
{
    bool adj;
    int weight;

    friend std::ostream& operator<<(std::ostream& os, const edge& edge)
    {
        os << "[" << edge.weight << "]";
        return os;
    }
};

class Graph
{
    private:
        edge adjMatrix[MAXVERTEXS][MAXVERTEXS];
    public:
        Graph();

        void addEdge(int vertex1, int vertex2, int weight);
        void removeEdge(int vertex1, int vertex2);
        void display();
};