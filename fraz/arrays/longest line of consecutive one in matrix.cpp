#include <bits/stdc++.h>
using namespace std;

//dp
// int longestLine(vector<vector<int>>& M) {
//     if(M.empty() || M[0].empty()) return 0;
//     int m = M.size(),n = M[0].size(),res = 0;
//     vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(4,0)));
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             if(M[i][j] == 0) continue;
//             for (int k = 0; k < 4; k++) dp[i][j][k] = 1;
//             if(j>0) dp[i][j][0] +=dp[i][j-1][0];
//             if(i>0) dp[i][j][1] +=dp[i-1][j][1];
//             if(i>0 && j>0) dp[i][j][2]+=dp[i-1][j-1][2];
//             if(i>0 && j<n-1) dp[i][j][3]+=dp[i-1][j+1][3];
//             res = max({res,dp[i][j][0],dp[i][j][1],dp[i][j][2],dp[i][j][3]});
//         }
//     }
//     return res;
// }

// space optimized
int longestLine(vector<vector<int>> &M){
    if(M.empty() || M[0].empty()) return 0;
    int m = M.size(),n = M[0].size(),res,row,col,diag,anti;
    res = row = col = diag = anti = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0,row = 0; j < n; j++) {
            row = M[i][j]?(row+1):0;
            res = max(res,row);
        }
    }
    for (int j = 0; j < n; j++) {
        for (int i = 0,col = 0; i < m; i++) {
            col = M[i][j]?(col+1):0;
            res = max(res,col);
        }
    }
    for (int k = 0; k < m+n; k++,diag = 0,anti = 0) {
        for (int i = max(m - 1 - k,0),j = max(0,k - m +1); i <m && j<n; i++,j++) {
            diag = M[i][j]?diag+1:0;
            res = max(res,diag);
        }
        for (int i = min(k,m-1),j = max(0,k - m +1); i >=0 && j<n; i--,j++) {
            anti = M[i][j]?anti+1:0;
            res = max(res,anti);
        }
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/longest-line-of-consecutive-one-in-matrix/
    return 0;
}
