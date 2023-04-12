#include <iostream>
#include <stack>
#include <queue>
#include "WeightedGraph.h"
#include "Vertex.h"

using namespace std;

WeightedGraph::WeightedGraph(){
        start = nullptr;
}

void WeightedGraph::insertVertex(char node){
        Vertex* vertex = new Vertex();
        vertex->node = node;
        vertex->next = nullptr;
        vertex->down = start;
        start = vertex;
}

void WeightedGraph::insertEdge(char node1, char node2, int weight){
        if (start == nullptr) {
                cout << "No such vertices!" << endl;
                return;
        }
        Vertex* temp = start;
        while (temp != nullptr) {
                if (temp->node == node1) {
                        Vertex* vertex = new Vertex();
                        vertex->node = node2;
                        vertex->weight = weight;
                        vertex->down = nullptr;
                        vertex->next = temp->next;
                        temp->next = vertex;
                        return;
                }
                temp = temp->down;
        }
}
Vertex* WeightedGraph::getVertex(char node){
        Vertex* temp = start;
        while (temp != nullptr) {
                if (temp->node == node)
                        return temp;
                temp = temp->down;
        }
        return temp;
}
void WeightedGraph::unvisitedVertices(){
        Vertex* temp = start;
        while (temp != nullptr) {
                temp->visited = false;
                temp = temp->down;
        }
}

void WeightedGraph::DFS(char source){
        cout << "DFS traversal: ";
        int totalCost = 0;
        stack<Vertex*> stack;
        Vertex* u = getVertex(source);
        stack.push(u);

        while (!stack.empty()) {
                Vertex* v = stack.top();
                stack.pop();
                if (getVertex(v->node)->visited ==false) {
                        cout<<v->node<<"->";
                        totalCost += v->weight;
                        getVertex(v->node)->visited = true;
                }
                Vertex* temp = getVertex(v->node);
                while (temp != nullptr) {
                        if (getVertex(temp->node)->visited == false)
                                stack.push(temp);
                        temp = temp->next;
                }
        }
        cout << endl;
        cout << "Total cost: " << totalCost << endl;

}

void WeightedGraph::BFS(char source){
        cout << "BFS traversal: ";
        int totalCost = 0;
        queue<Vertex*> queue;
        Vertex* u = getVertex(source);
        queue.push(u);

        while (!queue.empty()) {
                Vertex* v = queue.front();
                queue.pop();
                if (getVertex(v->node)->visited == false) {
                        cout << v->node << "->";
                        totalCost += v->weight;
                        getVertex(v->node)->visited = true;
                }
                Vertex* temp = getVertex(v->node);
                while (temp != nullptr) {
                        if (getVertex(temp->node)->visited == false)
                                queue.push(temp);
                        temp = temp->next;
                }
        }
        cout << endl;
        cout << "Total cost: " << totalCost << endl;

}

void WeightedGraph::print() {
        Vertex* temp1 = start;
        while (temp1 != nullptr) {
                cout << temp1->node << ": ";
                Vertex* temp2 = temp1->next;
                while (temp2 != nullptr) {
                        cout << "->" << temp2->node;
                        temp2 = temp2->next;
                }
                cout << endl;
                cout << "|" << endl;
                temp1 = temp1->down;
        }
}
