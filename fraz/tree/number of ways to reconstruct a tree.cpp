#include <iostream>
using namespace std;

int checkWays(vector<vector<int>> &pairs){
    unordered_map<int,unordered_set<int>> adj;
    for (int i = 0; i < pairs.size(); i++) {
        adj[pairs[i][0]].insert(pairs[i][1]);
        adj[pairs[i][1]].insert(pairs[i][0]);
    }
    priority_queue<pair<int,int>> pq;
    for (auto &[node,neighbours] : adj) pq.push({neighbours.size(),node});
    int totalNodes = pq.size();
    int result = 1;
    unordered_set<int> visited;
    while(!pq.empty()){
        auto[degree,curNode] = pq.top();pq.pop();
        int parent = -1;
        int parentDegree = INT_MAX;
        for (auto &neighbour : adj[curNode]) {
            if(visited.count(neighbour) && adj[neighbour].size()<parentDegree && adj[neighbour].size()>= degree){
                parent = neighbour;
                parentDegree = adj[neighbour].size();
            }
        }
        visited.insert(curNode);
        if(parent == -1){
            if(degree != totalNodes-1) return 0;
            continue;
        }
        for (auto &neighbour : adj[curNode]) {
            if(neighbour == parent) continue;
            if(!adj[parent].count(neighbour)) return 0;
        }
        if(degree == parentDegree) result = 2;
    }
    return result;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/number-of-ways-to-reconstruct-a-tree/discuss/1009393/C%2B%2B-O(nlogn)-Soln-with-comments-descriptive-variable-naming-time-and-space-complexity-analysis.
	return 0;
}

