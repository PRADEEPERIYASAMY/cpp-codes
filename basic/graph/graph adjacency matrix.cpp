#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

class Graph{
    private:
    bool ** adjMatrix;
    int numVertices;
    public:
    Graph(int numVertices){
        this->numVertices = numVertices;
        adjMatrix = new bool*[numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjMatrix[i] = new bool[numVertices];
            for (int j = 0; j < numVertices; j++) {
                adjMatrix[i][j]=false;
            }
        }
    }
    
    void addEdge(int i,int j){
        adjMatrix[i][j] = true;
        adjMatrix[i][j] = true;
    }
    
    void removeEdge(int i,int j){
        adjMatrix[i][j] = false;
        adjMatrix[j][i] = false;
    }
    
    void toString(){
        for (int i = 0; i < numVertices; i++) {
            cout<<i<<" : ";
            for (int j = 0; j < numVertices; j++) cout<<adjMatrix[i][j]<<" ";
            cout<<endl;
        }
    }
};

int main(){
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.toString();
  
    return 0;
}

