#include <iostream>
using namespace std;

void dfs(unordered_map<int,vector<int>> &graph,vector<int> &nodeColor,vector<bool> &visited,int &color,int node){
    visited[node] = true;
    nodeColor[node] = color;
    for (auto &v : graph[node]) if(!visited[v]) dfs(graph,nodeColor,visited,color,v);
}

bool equationsPossible(vector<string>& equations) {
    unordered_map<int,vector<int>> graph;
    vector<bool> visited('z'+1,false);
    vector<int> nodeColor('z'+1,-1);
    for (auto &e : equations) if(e[1] == '=') graph[e[0]].push_back(e[3]),graph[e[3]].push_back(e[0]);
    int color = 0;
    for (int i = 'a'; i <= 'z'; i++) {
        if(!visited[i]) dfs(graph,nodeColor,visited,color,i);
        color++;
    }
    for (auto &e : equations) if(e[1] == '!' && nodeColor[e[0]] == nodeColor[e[3]]) return false;
    return true;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/satisfiability-of-equality-equations/discuss/673606/C%2B%2B-clean-solution-DFS-and-Union-find
	return 0;
}

