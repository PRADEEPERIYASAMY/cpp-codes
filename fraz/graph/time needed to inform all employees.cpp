#include <iostream>
using namespace std;

int dfs(vector<vector<int>> &graph,int src,vector<int> &informTime){
    int time = 0;
    for (auto &n : graph[src]) time = max(time,dfs(graph,n,informTime));
    return informTime[src]+time;
}

int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    vector<vector<int>> graph(n);
    for (int i = 0; i < manager.size(); i++) if(manager[i]!= -1) graph[manager[i]].push_back(i);
    return dfs(graph,headID,informTime);
}
int main() {
	// leetcode
	// https://leetcode.com/problems/time-needed-to-inform-all-employees/discuss/532487/C%2B%2B-DFS
	return 0;
}

