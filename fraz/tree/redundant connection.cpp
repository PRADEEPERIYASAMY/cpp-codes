#include <iostream>
using namespace std;

// DFS
// bool hasCycle(int start,int end,unordered_map<int,unordered_set<int>> &graph,int pre){
//     if(graph[start].count(end)) return true;
//     for (auto &i : graph[start]) {
//         if(i == pre) continue;
//         if(hasCycle(i,end,graph,start)) return true;
//     }
//     return false;
// }

// vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//     unordered_map<int,unordered_set<int>> graph;
//     for (auto &i : edges) {
//         if(hasCycle(i[0],i[1],graph,-1)) return i;
//         graph[i[0]].insert(i[1]);
//         graph[i[1]].insert(i[0]);
//     }
//     return {};
// }

// BFS -- showing some error
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    unordered_map<int,unordered_set<int>> graph;
    for (auto &i : edges) {
        queue<int> q({i[0]});
        unordered_set<int> s({i[0]});
        while(!q.empty()){
            auto &t = q.front();q.pop();
            if(graph[t].count(i[1])) return i;
            for (auto &x : graph[t]) {
                if(s.count(x)) continue;
                q.push(x);
                s.insert(x);
            }
        }
        graph[i[0]].insert(i[1]);
        graph[i[1]].insert(i[0]);
    }
    return {};
}

int main() {
	// leetcode
	// https://leetcode.com/problems/redundant-connection/
	return 0;
}

