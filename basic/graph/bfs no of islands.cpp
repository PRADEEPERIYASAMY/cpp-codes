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
        for (auto &i : adj[u]) {
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int BFSDin(vector<int> adj[],int v){
    int c = 0;
    bool visited[v] = {false};
    for (int i = 0; i < v; i++) {
        if(visited[i] == false){
            BFS(adj,i,visited);
            c++;
        }
    }
    return c;
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

	cout << "Number of islands: "<<BFSDin(adj,V);  

	return 0; 
}

