#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

void topologicalSort(vector<int> adj[],int v){
    vector<int> in_degree(v,0);
    for (int i = 0; i < v; i++) for (auto &x : adj[i]) in_degree[x]++;
    queue<int> q;
    for (int i = 0; i < v; i++) if(in_degree[i] == 0) q.push(i);
    while(!q.empty()){
        int i = q.front();
        q.pop();
        cout<<i<<" ";
        for (auto &x : adj[i]) if(--in_degree[x] == 0) q.push(x);
    }
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}

int main(){
    
    int V=5;
	vector<int> adj[V];
	addEdge(adj,0, 2); 
    addEdge(adj,0, 3); 
    addEdge(adj,1, 3); 
    addEdge(adj,1, 4); 
    addEdge(adj,2, 3);   
  
    cout << "Following is a Topological Sort of\n"; 
    topologicalSort(adj,V);

	return 0;
}

