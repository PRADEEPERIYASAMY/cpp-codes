#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

void BFS(vector<int> adj[],int s,bool visited[]){
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout<<u<<" ";
        for (auto &i : adj[u]) {
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFSDin(vector<int> adj[],int v){
    bool visited[v] = {false};
    for (int i = 0; i < v; i++) {
        if(visited[i] == false) BFS(adj,i,visited);
    }
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    int V=7;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,2,3); 
	addEdge(adj,1,3); 
	addEdge(adj,4,5);
	addEdge(adj,5,6);
	addEdge(adj,4,6);

	cout << "Following is Breadth First Traversal: "<< endl; 
	BFSDin(adj,V); 

	return 0; 
}

