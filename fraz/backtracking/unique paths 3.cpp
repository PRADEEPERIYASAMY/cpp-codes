#include <iostream>
using namespace std;

void dfs(vector<vector<int>> &grid,vector<vector<bool>> &visited,int x,int y,int end_x,int end_y,int &zeros,int &res){
    if(x<0 || x>= grid.size() || y<0 || y>= grid[0].size() || grid[x][y]<0 || visited[x][y]) return ;
    if(x == end_x && y == end_y){
        if(zeros == 0) res++;
        return;
    }
    visited[x][y] = true;
    zeros--;
    dfs(grid,visited,x+1,y,end_x,end_y,zeros,res);
    dfs(grid,visited,x-1,y,end_x,end_y,zeros,res);
    dfs(grid,visited,x,y-1,end_x,end_y,zeros,res);
    dfs(grid,visited,x,y+1,end_x,end_y,zeros,res);
    zeros++;
    visited[x][y] = false;
}

int uniquePathsIII(vector<vector<int>>& grid) {
    int m = grid.size(),n = grid[0].size();
    int res = 0,zeros = 0,start_x = -1,start_y = -1,end_x = -1,end_y = -1;
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(grid[i][j] == 0) zeros++;
            else if(grid[i][j] == 1){
                zeros++;
                start_x =i,start_y = j;
            }else if(grid[i][j] == 2){
                end_x = i,end_y = j;
            }
        }
    }
    dfs(grid,visited,start_x,start_y,end_x,end_y,zeros,res);
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/unique-paths-iii/
	return 0;
}

