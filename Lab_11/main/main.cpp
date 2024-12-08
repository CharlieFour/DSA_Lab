#include <iostream>
#include "..\lib\graph.h"

using namespace std;

int main()
{
    Graph graph;

    graph.addEdge(0, 1, 5);
    graph.addEdge(0, 2, 9);
    graph.addEdge(1, 2, 4);
    graph.addEdge(2, 3, 7);

    graph.display();

    graph.removeEdge(0, 2);
    graph.removeEdge(2, 3);
    cout << "\nAfter removing edges\n";
    graph.display();

    system("pause");
    return 0;
}