#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

void BFS(vector<int> adj[],int v,int s){
    bool visited[v]={false};
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

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    int V=5;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,1,2); 
	addEdge(adj,2,3); 
	addEdge(adj,1,3);
	addEdge(adj,3,4);
	addEdge(adj,2,4);

	cout << "Following is Breadth First Traversal: "<< endl; 
	BFS(adj,V,0); 

	return 0;
}

