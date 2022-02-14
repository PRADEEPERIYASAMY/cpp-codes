#include <iostream>
using namespace std;

void dfs(vector<vector<int>> &graph,vector<bool> &visited,int src){
    visited[src] = true;
    for (auto &i : graph[src]) if(!visited[i]) dfs(graph,visited,i);
}

int makeConnected(int n, vector<vector<int>>& connections) {
    if(connections.size()<n-1) return -1;
    vector<vector<int>> graph(n);
    for (auto &v : connections) graph[v[0]].push_back(v[1]),graph[v[1]].push_back(v[0]);
    vector<bool> visited(n,false);
    int components = 0;
    for (int i = 0; i < n; i++) {
        if(!visited[i]){
            dfs(graph,visited,i);
            components++;
        }
    }
    return components-1;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/number-of-operations-to-make-network-connected/discuss/717403/C%2B%2B-or-DFS-or-Number-of-Islands-or-Detailed-explanation
	return 0;
}

