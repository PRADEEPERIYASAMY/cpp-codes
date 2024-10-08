#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

void DFS(vector<int> adj[],int s,stack<int> &st,bool visited[]){
    visited[s] = true;
    for (auto &x : adj[s]) if(!visited[x]) DFS(adj,x,st,visited);
    st.push(s);
}

void topologicalSort(vector<int> adj[],int v){
    bool visited[v] = {false};
    stack<int> st;
    for (int i = 0; i < v; i++) {
        if(!visited[i]) DFS(adj,i,st,visited);
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}

int main(){
    
    int V=5;
	vector<int> adj[V];
	addEdge(adj,0, 1); 
    addEdge(adj,1, 3); 
    addEdge(adj,2, 3); 
    addEdge(adj,3, 4); 
    addEdge(adj,2, 4);  
  
    cout << "Following is a Topological Sort of\n"; 
    topologicalSort(adj,V);

	return 0;
}

