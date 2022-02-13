#include <iostream>
using namespace std;
#define WHITE 0
#define RED 1
#define BLUE 2

bool possibleBipartition(int N, vector<vector<int>> &edges) {
    vector<vector<int>> adj(N+1);
    vector<int> color(N+1,WHITE);
    vector<bool> visited(N+1,false);
    for (auto &edge : edges) adj[edge[0]].push_back(edge[1]),adj[edge[1]].push_back(edge[0]);
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if(!visited[i]){
            color[i] = RED;
            q.push(i);
            while(!q.empty()){
            int u = q.front();q.pop();
            if(visited[u]) continue;
            visited[u] = true;
            for (auto &v : adj[u]) {
                if(color[v] == color[u]) return false;
                if(color[u] == RED) color[v] = BLUE;
                else color[v] = RED;
                q.push(v);
            }
            }
        }
    }
    return true;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/possible-bipartition/discuss/654887/C%2B%2B-BFS-with-detailed-explanation
	return 0;
}

