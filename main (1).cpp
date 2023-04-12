// Name: Dharma Kotecha
// Date: 11/04/2023
// Program that implements a weighted directed graph

#include <iostream>
#include "WeightedGraph.h"
using namespace std;

int main()
{
    WeightedGraph G;
    G.insertVertex('A');
    G.insertVertex('B');
    G.insertVertex('D');
    G.insertVertex('F');
    G.insertVertex('N');

    G.insertEdge('N','F',11);
    G.insertEdge('F','N',33);
    G.insertEdge('B','F',13);
    G.insertEdge('N','B',22);
    G.insertEdge('B','D',23);
    G.insertEdge('N','A',33);
    G.insertEdge('F','A',43);
    G.insertEdge('A','B',14);
    G.insertEdge('D','A',5 );
    cout << "Adjacency graph: " << endl;
    G.print();
    cout << "Graph traversal: " << endl;
    G.DFS('F');
    G.unvisitedVertices();
    G.BFS('F');

    return 0;
}

