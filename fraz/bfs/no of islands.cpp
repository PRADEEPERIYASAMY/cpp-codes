#include <iostream>
using namespace std;

void helper(vector<vector<char>> &grid,vector<vector<bool>> &visited,vector<vector<int>> &dirs,int i,int j){
    if(i< 0 || i>= grid.size() || j< 0 || j>= grid[0].size() || visited[i][j] || grid[i][j] == '0') return ;
    visited[i][j] = true;
    for (auto &dir : dirs) {
        int x = i +dir[0],y = j+dir[1];
        helper(grid,visited,dirs,x,y);
    }
}

int numIslands(vector<vector<char>>& grid) {
    if(grid.empty() || grid[0].empty()) return 0;
    int m = grid.size(),n = grid[0].size(), res = 0;
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    vector<vector<int>> dirs({{1,0},{-1,0},{0,-1},{0,1}});
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(grid[i][j] == '1' && !visited[i][j]){
                helper(grid,visited,dirs,i,j);
                ++res;
            }
        }
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/number-of-islands/
	return 0;
}

