#include <iostream>
using namespace std;

// dp time limit exceeded
// int superEggDrop(int k, int n) {
//     vector<vector<int>> dp(n+1,vector<int>(k+1,0));
//     for (int i = 1; i <= n; i++) dp[i][1] = i;
//     for (int j = 2; j <= k; j++) {
//         for (int i = 1; i <= n; i++) {
//             dp[i][j] = i;
//             for (int t = 1; t < i; t++) {
//                 dp[i][j] = min(dp[i][j],max(dp[t-1][j-1],dp[i-t][j])+1);
//             }
//         }
//     }
//     return dp[n][k];
// }

int superEggDrop(int k,int n){
    vector<vector<int>> dp(n+1,vector<int>(k+1,0));
    int m = 0;
    while(dp[m][k]<n){
        m++;
        for (int t = 1; t <= k; t++) {
            dp[m][t] = dp[m-1][t-1]+dp[m-1][t]+1;
        }
    }
    return m;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/super-egg-drop/
	// https://leetcode.com/problems/super-egg-drop/discuss/158974/C%2B%2BJavaPython-2D-and-1D-DP-O(KlogN)
	return 0;
}

