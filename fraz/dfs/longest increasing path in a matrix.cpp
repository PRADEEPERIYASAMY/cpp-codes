#include <iostream>
using namespace std;

// DFS Recursion + Memoization
int helper(vector<vector<int>> &matrix,int i,int j,vector<vector<int>> &memo,vector<vector<int>> &dirs){
    if(memo[i][j] != 0) return memo[i][j];
    int cur = 1;
    for (auto &dir : dirs) {
        int x = dir[0]+i,y = dir[1]+j;
        if(x<0 || x>= matrix.size() || y<0 || y>= matrix[0].size() || matrix[x][y]<= matrix[i][j]) continue;
        int len = helper(matrix,x,y,memo,dirs)+1;
        cur = max(cur,len);
    }
    return memo[i][j] = cur;
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    if(matrix.empty()) return 0;
    int m = matrix.size(),n = matrix[0].size();
    vector<vector<int>> dirs({{1,0},{-1,0},{0,1},{0,-1}}),memo(m,vector<int>(n));
    int res = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            res = max(res,helper(matrix,i,j,memo,dirs));
        }
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
	return 0;
}

