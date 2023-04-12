#ifndef VERTEX_H
#define VERTEX_H

#include <string>
using namespace std;


class Vertex{

    public:
         char node;
        int weight;
        Vertex* next;
        Vertex* down;
        bool visited;
        Vertex() {
                visited = false;
                next = nullptr;
                down = nullptr;
        }
};
#endif // VERTEX_H
