#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

bool DFSRec(vector<int> adj[],int s,bool visited[],int parent){
    visited[s] = true;
    for (auto &i : adj[s]) {
        if(!visited[i]){
            if(DFSRec(adj,i,visited,s)) return true;
        }else if(i != parent) return true;
    }
    
    return false;
}

bool DFS(vector<int> adj[],int v){
    bool visited[v] = {false};
    for (int i = 0; i < v; i++) {
        if(!visited[i]){
           if( DFSRec(adj,i,visited,-1)) return true;
        }
    }
    return false;
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    
    int V=6;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,1,2); 
	addEdge(adj,2,4); 
	addEdge(adj,4,5); 
	addEdge(adj,1,3);
	addEdge(adj,2,3);

	if(DFS(adj,V))
	    cout<<"Cycle found";
	else
	    cout<<"No cycle found";

	return 0;   
}

