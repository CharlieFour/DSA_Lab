#include "graph.h"

Graph::Graph()
{
    for (int i = 0; i < MAXVERTEXS; i++)
    {
        for (int j = 0; j < MAXVERTEXS; j++)
        {
            adjMatrix[i][j] = {0, 0};
        }
    }
}
void Graph::addEdge(int vertex1, int vertex2, int weight)
{
    adjMatrix[vertex1][vertex2].adj = true;
    adjMatrix[vertex2][vertex1].adj = true;
    adjMatrix[vertex1][vertex2].weight = weight;
    adjMatrix[vertex2][vertex1].weight = weight;
}
void Graph::removeEdge(int vertex1, int vertex2)
{
    adjMatrix[vertex1][vertex2].adj = false;
    adjMatrix[vertex2][vertex1].adj = false;
    adjMatrix[vertex1][vertex2].weight = 0;
    adjMatrix[vertex2][vertex1].weight = 0;
}

void Graph::display()
{
    for (int i = 0; i < MAXVERTEXS; i++)
    {
        for (int j = 0; j < MAXVERTEXS; j++)
        {
            std::cout << adjMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}