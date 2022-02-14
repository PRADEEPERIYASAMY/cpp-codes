#include <iostream>
using namespace std;

void dfs(vector<vector<int>> &graph,int i,int j){
    if(i<0 || i>= graph.size() || j<0 || j>= graph[0].size() || graph[i][j] != 0) return;
    graph[i][j] = 1;
    dfs(graph,i+1,j);
    dfs(graph,i-1,j);
    dfs(graph,i,j-1);
    dfs(graph,i,j+1);
}

int regionsBySlashes(vector<string>& grid) {
    int n = grid.size(),res = 0;
    vector<vector<int>> graph(3*n,vector<int>(3*n,0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(grid[i][j] == '/') graph[3*i][3*j+2] = graph[3*i+1][3*j+1] = graph[3*i+2][3*j] = 1;
            if(grid[i][j] == '\\') graph[3*i][3*j] = graph[3*i+1][3*j+1] = graph[3*i+2][3*j+2] = 1;
        }
    }
    for (int i = 0; i < 3*n; i++) {
            for (int j = 0; j < 3*n; j++) {
                if(graph[i][j] == 0) {
                    dfs(graph,i,j);
                    res++;
                }
            }
        }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/regions-cut-by-slashes/
	return 0;
}

