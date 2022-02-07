#include <iostream>
using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> colors(n,0);
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if(colors[i]) continue;
        colors[i] = 1;
        q.push(i);
        while(!q.empty()){
            int temp = q.front();q.pop();
            for (auto &x : graph[temp]) {
                if(!colors[x]){
                    colors[x] = -colors[temp];
                    q.push(x);
                }
                else if(colors[x] == colors[temp]) return false;
            }
        }
    }
    return true;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/is-graph-bipartite/discuss/1065074/C%2B%2B-Super-Simple-Easy-BFS
	return 0;
}

