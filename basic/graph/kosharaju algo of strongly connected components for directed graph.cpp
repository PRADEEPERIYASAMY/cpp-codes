#include <bits/stdc++.h> 
#define INF INT_MAX 
using namespace std; 
#define V 5

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}

void getTransponse(vector<int> adj[],vector<int> trans[]){
    for (int i = 0; i < V; i++) {
        for (auto &x : adj[i]) {
            addEdge(trans,x,i);
        }
    }
}

void fillorder(vector<int> adj[],int s,bool visited[],stack<int> &st){
    visited[s] = true;
    for (auto &x : adj[s]) if(!visited[x]) fillorder(adj,x,visited,st);
    st.push(s);
}

void DFSutil(vector<int> trans[],int s,bool visited[]){
    visited[s] = true;
    cout<<s<<" ";
    for (auto &x : trans[s]) if(!visited[x]) DFSutil(trans,x,visited);
}

void printSCCs(vector<int> adj[]){
    stack<int> s;
    bool visited[V] = {false};
    for (int i = 0; i < V; i++) if(!visited[i]) fillorder(adj,i,visited,s);
    vector<int> trans[V];
    getTransponse(adj,trans);
    for(int i = 0; i < V; i++) visited[i] = false; 
    
    while(!s.empty()){
        int v = s.top();
        s.pop();
        if(!visited[v]){
            DFSutil(trans,v,visited);
            cout<<endl;
        }
    }
}

int main() { 
	vector<int> adj[V];
	addEdge(adj,1,0); 
	addEdge(adj,0,2); 
	addEdge(adj,2,1); 
	addEdge(adj,0,3); 
	addEdge(adj,3,4);
	
	cout << "Following are strongly connected components in given graph \n"; 
	printSCCs(adj); 

	return 0; 
}

