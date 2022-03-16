#include <bits/stdc++.h>
using namespace std;

// int islandPerimeter(vector<vector<int>> &grid){
//     if(grid.empty() || grid[0].empty()) return 0;
//     int island = 0,neighbor = 0,m = grid.size(),n = grid[0].size();
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             if(grid[i][j] == 1){
//                 island++;
//                 if(i<m-1 && grid[i+1][j] == 1) neighbor++;
//                 if(j<n-1 && grid[i][j+1] == 1) neighbor++;
//              }
//         }
//     }
//     return 4*island - 2*neighbor;
// }

// alternative
int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1) {
                    res += 4;
                    if (j+1<n && grid[i][j+1]==1) res--;
                    if (i+1<m && grid[i+1][j]==1) res--;
                    if (i-1>=0 && grid[i-1][j]==1) res--;
                    if (j-1>=0 && grid[i][j-1]==1) res--;
                }
            }
        }  
        return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/island-perimeter/
    return 0;
}
