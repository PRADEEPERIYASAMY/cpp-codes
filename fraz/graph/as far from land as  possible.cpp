#include <iostream>
using namespace std;

int maxDistance(vector<vector<int>>& grid) {
    const int n = grid.size();
    const vector<vector<int>> dirs({{-1,0},{1,0},{0,-1},{0,1}});
    queue<pair<int,int>> q;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if(grid[i][j] == 1) q.push({i,j});
    int level = 0;
    while(!q.empty()){
        level++;
        for (int k = q.size()-1; k>= 0; k--) {
            auto[r,c] = q.front();q.pop();
            for (auto &dir : dirs) {
                int x = r+dir[0],y = c+dir[1];
                if(x<0 || x>= n || y<0 || y>= n || grid[x][y] != 0) continue;
                grid[x][y] = level+1;
                q.push({x,y});
            }
        }
    }
    return level == 1?-1:level-1;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/as-far-from-land-as-possible/
	return 0;
}

