#include <iostream>
using namespace std;

bool checkCycle(int src,vector<vector<int>> &graph,vector<bool> &visited,vector<bool> &checked){
    visited[src] = true;
    checked[src] = true;
    for (int i = 0; i < graph[src].size(); i++) {
        if(!visited[graph[src][i]]) {
            if(checkCycle(graph[src][i],graph,visited,checked)) return true;
        }
        else if(checked[graph[src][i]]) return true;
    }
    checked[src] = false;
    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    vector<int> res;
    vector<bool> visited(graph.size(),false),checked(graph.size(),false);
    for (int i = 0; i < graph.size(); i++) if(!checkCycle(i,graph,visited,checked)) res.push_back(i);
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/find-eventual-safe-states/discuss/1312689/Simple-loop-detection-Algorithm-C%2B%2BorDFSororwith-brief-Explanation
	return 0;
}

