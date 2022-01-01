#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

// since topological sort can be used only for dag, it wonnt use for cycle but cane use this method to detect cycle
void topologicalSort(vector<int> adj[],int v){
    vector<int> in_degree(v,0);
    for (int i = 0; i < v; i++) for (auto &x : adj[i]) in_degree[x]++;
    queue<int> q;
    for (int i = 0; i < v; i++) if(in_degree[i] == 0) q.push(i);
    int count = 0;
    while(!q.empty()){
        int i = q.front();
        q.pop();
        for (auto &x : adj[i]) if(--in_degree[x] == 0) q.push(x);
        count++;
    }
    if (count != v) cout << "There exists a cycle in the graph\n"; 
    else cout << "There exists no cycle in the graph\n";
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}

int main(){
    
    int V=5;
	vector<int> adj[V];
	addEdge(adj,0, 1); 
    addEdge(adj,4, 1); 
    addEdge(adj,1, 2); 
    addEdge(adj,2, 3); 
    addEdge(adj,3, 1);  
  
    topologicalSort(adj,V);

	return 0;
}

