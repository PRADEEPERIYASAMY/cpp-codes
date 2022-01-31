#include <iostream>
using namespace std;

//dfs
// void helper(vector<vector<int>> &grid,vector<vector<bool>> &visited,int i,int j,int &cur){
//     if(i<0 || i>= grid.size() || j<0 || j>= grid[0].size() || grid[i][j] != 1 || visited[i][j]) return;
//     visited[i][j] = true;
//     cur++;
//     helper(grid,visited,i-1,j,cur);
//     helper(grid,visited,i+1,j,cur);
//     helper(grid,visited,i,j-1,cur);
//     helper(grid,visited,i,j+1,cur);
// }

// int maxAreaOfIsland(vector<vector<int>>& grid) {
//     if(grid.empty() || grid[0].empty()) return 0;
//     int res = 0,m = grid.size(),n = grid[0].size(),cur = 0;
//     vector<vector<bool>> visited(m,vector<bool>(n,false));
//     for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) if(grid[i][j] == 1 && !visited[i][j]) helper(grid,visited,i,j,cur),res = max(res,cur),cur=0;
//     return res;
// }

//bfs
int maxAreaOfIsland(vector<vector<int>>& grid) {
    if(grid.empty() || grid[0].empty()) return 0;
    int res = 0,m = grid.size(),n = grid[0].size(),cnt = 0;
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    vector<vector<int>> dirs({{1,0},{-1,0},{0,-1},{0,1}});
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(grid[i][j] != 1) continue;
            cnt = 0;
            queue<pair<int,int>> q({{i,j}});
            visited[i][j] = true;
            while(!q.empty()){
                res = max(res,++cnt);
                auto t = q.front();q.pop();
                for (auto &i : dirs) {
                    int x = t.first+i[0],y = t.second+i[1];
                    if(x<0 || x>=m|| y<0 || y>= n || grid[x][y] != 1 || visited[x][y]) continue;
                    visited[x][y] = true;
                    q.push({x,y});
                }
            }
        }
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/max-area-of-island/
	return 0;
}

