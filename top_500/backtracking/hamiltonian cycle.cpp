#include <bits/stdc++.h>
using namespace std;
#define V 5

bool isSafe(int v,bool graph[V][V],int path[],int pos){
    if(graph[path[pos-1]][v] == 0) return false;
    for (int i = 0; i < pos; i++) if(path[i] == v) return false;
    return true;
}

bool HamiltonianUtil(bool graph[V][V],int path[],int pos){
    if(pos == V){
        if(graph[path[pos-1]][path[0]] == 1) return true;
        else return false;
    }
    for (int i = 1; i < V; i++) {
        if(isSafe(i,graph,path,pos)){
            path[pos] = i;
            if(HamiltonianUtil(graph,path,pos+1)) return true;
            path[pos] = -1;
        }
    }
    return false;
}

void printSolution(int path[]){
    cout<<"Solution Eisits: Following is one Hamiltonian cycle \n";
    for (int i = 0; i < V; i++) cout<<path[i]<<" ";
    cout<<path[0]<<" ";
    cout<<"\n";
}

bool hamCycle(bool graph[V][V]){
    int path[V];
    memset(path,-1,sizeof(path));
    path[0] = 0;
    if(HamiltonianUtil(graph,path,1) == false){
        cout<<"Solution does not exist";
        return false;
    }
    printSolution(path);
    return true;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/hamiltonian-cycle-backtracking-6/
	bool graph1[V][V] = {{0, 1, 0, 1, 0},
                        {1, 0, 1, 1, 1},
                        {0, 1, 0, 0, 1},
                        {1, 1, 0, 0, 1},
                        {0, 1, 1, 1, 0}};
    hamCycle(graph1);
    bool graph2[V][V] = {{0, 1, 0, 1, 0},
                         {1, 0, 1, 1, 1},
                         {0, 1, 0, 0, 1},
                         {1, 1, 0, 0, 0},
                         {0, 1, 1, 0, 0}};
    hamCycle(graph2);
	return 0;
}

