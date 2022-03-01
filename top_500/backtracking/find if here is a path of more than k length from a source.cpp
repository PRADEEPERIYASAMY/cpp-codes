#include <bits/stdc++.h>
using namespace std;

bool pathMoreThankUtil(vector<vector<int>> &graph,int src,int k,vector<bool> &path){
    if(k<=0) return true;
    for (int i = 0; i < 9; i++) {
        if(graph[src][i] == 0) continue;
        if(path[i] == true) continue;
        if(graph[src][i]>=k) return true;
        path[i] = true;
        if(pathMoreThankUtil(graph,i,k-graph[src][i],path)) return true;
        path[i] = false;
    }
    return false;
}

bool pathMoreThank(vector<vector<int>> &graph,int src,int k){
    vector<bool> path(9,false);
    path[src] = true;
    return pathMoreThankUtil(graph,src,k,path);
}

void addEdge(vector<vector<int>> &graph,int src,int dest,int w){
    graph[src][dest] = w;
    graph[dest][src] = w;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/find-if-there-is-a-path-of-more-than-k-length-from-a-source/
	vector<vector<int>> graph(9,vector<int>(9,0));
	addEdge(graph,0, 1, 4);
    addEdge(graph,0, 7, 8);
    addEdge(graph,1, 2, 8);
    addEdge(graph,1, 7, 11);
    addEdge(graph,2, 3, 7);
    addEdge(graph,2, 8, 2);
    addEdge(graph,2, 5, 4);
    addEdge(graph,3, 4, 9);
    addEdge(graph,3, 5, 14);
    addEdge(graph,4, 5, 10);
    addEdge(graph,5, 6, 2);
    addEdge(graph,6, 7, 1);
    addEdge(graph,6, 8, 6);
    addEdge(graph,7, 8, 7);
	int src = 0;
	int k = 62;
	pathMoreThank(graph,src,k)? cout << "Yes\n" : cout << "No\n";
	k = 60;
	pathMoreThank(graph,src,k)? cout << "Yes\n" : cout << "No\n";
	return 0;
}

