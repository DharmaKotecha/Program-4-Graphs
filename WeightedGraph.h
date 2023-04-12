#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H

#include <vector>
#include "WeightedGraph.h"

class WeightedGraph{

    private:
        Vertex* start;

    public:
        WeightedGraph();
        void insertVertex(char node);
        void insertEdge(char node1, char node2, int weight);
        Vertex* getVertex(char node);
        void unvisitedVertices();
        void DFS(char source);
        void BFS(char source);
        void print();
};

#endif // WEIGHTEDGRAPH_H
