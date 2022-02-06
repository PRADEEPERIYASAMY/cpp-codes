#include <iostream>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    if(grid.empty() || grid[0].empty()) return 0;
    int m = grid.size(),n = grid[0].size(),fresh_count = 0;
    queue<pair<int,int>> q;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(grid[i][j] == 1) fresh_count++;
            else if(grid[i][j] == 2) q.emplace(i,j);
        }
    }
    if(fresh_count == 0) return 0;
    int res = 0;
    vector<vector<int>> dirs({{-1,0},{1,0},{0,-1},{0,1}});
    while(!q.empty() && fresh_count){
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto t = q.front();q.pop();
            for (auto &dir : dirs) {
                int r = t.first + dir[0], c = t.second + dir[1];
                if(r<0 || r>= m || c<0 || c>= n || grid[r][c] != 1) continue;
                grid[r][c] = 2;
                fresh_count--;
                q.emplace(r,c);
            }
        }
        res++;
    }
    return fresh_count == 0?res:-1;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/rotting-oranges/
	return 0;
}

