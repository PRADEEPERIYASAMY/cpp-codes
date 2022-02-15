#include <iostream>
using namespace std;
// tarjan's algorithm
void dfs(int u,int pre,int &time,vector<int> &disc,vector<int> &low,vector<vector<int>> &graph,vector<vector<int>> &res){
    disc[u] = low[u] = ++time;
    for (auto &v : graph[u]) {
        if(v == pre) continue;
        if(disc[v] == -1){
            dfs(v,u,time,disc,low,graph,res);
            low[u] = min(low[u],low[v]);
            if(low[v]>disc[u]) res.push_back({u,v});
        }else low[u] = min(low[u],disc[v]);
    }
}

vector<vector<int> > criticalConnections(int n, vector<vector<int>>& connections) {
    vector<int> disc(n,-1),low(n,0);
    vector<vector<int>> graph(n),res;
    for (auto &i : connections) {
        graph[i[0]].emplace_back(i[1]);
        graph[i[1]].emplace_back(i[0]);
    }
    int time = 0;
    dfs(0,0,time,disc,low,graph,res);
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/critical-connections-in-a-network/
	return 0;
}

