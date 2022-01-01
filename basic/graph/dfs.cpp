#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

void DFSRec(vector<int> adj[],int s,bool visited[]){
    visited[s] = true;
    cout<<s<<" ";
    for (auto &i : adj[s]) {
        if(!visited[i]) DFSRec(adj,i,visited);
    }
}

int DFS(vector<int> adj[],int v,int s){
    bool visited[v] = {false};
    DFSRec(adj,s,visited);
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    
    int V=5;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,2,3); 
	addEdge(adj,1,3); 
	addEdge(adj,1,4);
	addEdge(adj,3,4);

	cout << "Following is Depth First Traversal: "<< endl; 
	DFS(adj,V,0); 

	return 0; 
}

