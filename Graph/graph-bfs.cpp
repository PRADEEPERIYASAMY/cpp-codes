#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void BFS(vector<int> adj[],int v,int s){
    vector<bool> visited(v, false);
    queue<int> queue;
    visited[s]= true;
    queue.push(s);
    while (!queue.empty()){
        int temp = queue.front();
        queue.pop();
        cout<<temp<<" ";
        for (auto x:adj[temp]) {
            if (!visited[x]){
                visited[x]= true;
                queue.push(x);
            }
        }
    }
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
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);

    printGraph(adj, V);

    //print BFS
    BFS(adj,V,0);

    return 0;
}
