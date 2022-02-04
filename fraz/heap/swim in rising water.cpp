#include <iostream>
using namespace std;

// BFS Dijkstra
// int swimInWater(vector<vector<int>>& grid) {
//     const vector<vector<int>> dirs({{-1,0},{1,0},{0,-1},{0,1}});
//     const int n = grid.size();
//     priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
//     pq.emplace(grid[0][0],0,0);
//     int res = 0;
//     grid[0][0] = -1;
//     while(!pq.empty()){
//         auto [elevation,i,j] = pq.top();pq.pop();
//         res = max(res,elevation);
//         if(i == n-1 && j == n-1) return res;
//         for (auto &dir : dirs) {
//             int x = i+dir[0],y = j+dir[1];
//             if(x<0 || x>= n || y< 0 || y>=n || grid[x][y] == -1) continue;
//             pq.emplace(grid[x][y],x,y);
//             grid[x][y] = -1;
//         }
//     }
//     return -1;
// }

// Binary Search + DFS
bool dfs(const vector<vector<int>>& grid, vector<vector<bool> >& visited, const vector<vector<int>>& dir, int waterLevel, int row, int col){
    const int n = grid.size();
    visited[row][col] = true;
    for (auto &d : dir) {
        int x = row+d[0],y = col+d[1];
        if(x<0 || x>= n || y<0 || y>= n || visited[x][y] || grid[x][y] > waterLevel) continue;
        if(x == n-1 && y == n-1) return true;
        if(dfs(grid,visited,dir,waterLevel,x,y)) return true;
    }
    return false;
}

bool valid(const vector<vector<int> >& grid, int waterLevel) {
    const int n = grid.size();
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    vector<vector<int>> dir({{-1,0},{1,0},{0,-1},{0,1}}); 
    return dfs(grid,visited,dir,waterLevel,0,0);
}

int swimInWater(vector<vector<int>>& grid) {
    const int n = grid.size();
    int low = grid[0][0],high = n*n-1;
    while(low<high){
        int mid = low+(high-low)/2;
        if(valid(grid,mid)) high = mid;
        else low = mid+1;
    }
    return low;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/swim-in-rising-water/
	return 0;
}

