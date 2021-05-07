#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void DFS_rec(vector<int> adj[], int s, vector<bool> &visited) {
    visited[s]= true;
    cout<<s<<" ";
    for(auto x:adj[s])
        if (!visited[x]) DFS_rec(adj,x,visited);
}

void DFS(vector<int> adj[],int v,int s){
    vector<bool> visited(v, false);
    DFS_rec(adj, s, visited);
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int V){
    for (int i = 0; i < V; i++){
        cout<<i<<": ";
        for (int x : adj[i])
            cout << x <<" ";
        cout<<"\n";
    }
}

int32_t main()
{
    int V = 4;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);

    printGraph(adj, V);

    //print DFS for graph
    DFS(adj,V,0);

    return 0;
}
