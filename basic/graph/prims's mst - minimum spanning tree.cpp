#include <bits/stdc++.h> 
#define INF INT_MAX 
using namespace std; 
#define V 4

// it's a greedy one
int primMST(int graph[V][V]){ 
    int key[V];
    int res = 0;
    fill(key,key+V,INT_MAX);
    bool mst[V] = {false};
    key[0] = 0;
    for (int i = 0; i < V; i++) {
        int u = -1;
        for (int j = 0; j < V; j++) {
            if(!mst[j] && (u == -1|| key[j]<key[u])) u = j; // index with minumum key
        }
        mst[u] = true;
        res+=key[u];
        for (int v = 0; v < V; v++) {
            if(graph[u][v] != 0 && !mst[v]) key[v] = min(key[v],graph[u][v]);
        }
    }
    return res;
}

int main() { 
	int graph[V][V] = { { 0, 5, 8, 0}, 
						{ 5, 0, 10, 15 }, 
						{ 8, 10, 0, 20 }, 
						{ 0, 15, 20, 0 },}; 

	cout<<primMST(graph); 

	return 0; 
}

