#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Graph{
private:
    bool **adjMatrix;
    int vertices;
public:
    Graph(int vertices);
    void addEdge(int i,int j);
    void removeEdge(int i,int j);
    void printGraph();
};

Graph::Graph(int vertices) {
    this->vertices = vertices;
    adjMatrix = new bool *[vertices];
    for (int i = 0; i < vertices; i++) {
        adjMatrix[i] = new bool [vertices];
        for (int j = 0; j < vertices; j++) {
            adjMatrix[i][j] = false;
        }
    }
}

void Graph::addEdge(int i, int j) {
    adjMatrix[i][j] = true;
    adjMatrix[i][j] = true;
}

void Graph::removeEdge(int i, int j) {
    adjMatrix[i][j] = false;
    adjMatrix[i][j] = false;
}

void Graph::printGraph() {
    for (int i = 0; i < vertices; i++) {
        cout<<i<<": ";
        for (int j = 0; j < vertices; j++) {
            cout<<adjMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int32_t main() {
    Graph graph(4);
    graph.addEdge(1,2);
    graph.addEdge(0,2);
    graph.addEdge(3,2);

    graph.printGraph();

    return 0;
}

