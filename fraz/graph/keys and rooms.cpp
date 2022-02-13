#include <iostream>
using namespace std;

//bfs 
// bool canVisitAllRooms(vector<vector<int>> &rooms){
//     unordered_set<int> visited;
//     queue<int> q({0});
//     while(!q.empty()){
//         int t = q.front();q.pop();
//         visited.insert(t);
//         for (auto &k : rooms[t]) if(!visited.count(k)) q.push(k);
//     }
//     return visited.size() == rooms.size();
// }

// dfs 
void dfs(vector<vector<int>> &rooms,unordered_set<int> &visited,int cur){
    visited.insert(cur);
    for (auto &k : rooms[cur]) if(!visited.count(k)) dfs(rooms,visited,k);
}

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    unordered_set<int> visited;
    dfs(rooms,visited,0);
    return visited.size() == rooms.size();
}

int main() {
	// leetcode
	// https://leetcode.com/problems/keys-and-rooms/discuss/135306/BFS-(9-lines-10ms)-and-DFS-(7-lines-18ms)-in-C%2B%2B-w-beginner-friendly-explanation
	return 0;
}

