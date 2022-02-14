#include <iostream>
using namespace std;

int countPalindromicSubsequences(string s) {
    int n =s.size(),m = 1e9+7;
    vector<vector<int>> dp(n,vector<int>(n,0));
    for (int i = 0; i < n; i++) dp[i][i] = 1;
    for (int len = 1; len < n; len++) {
        for (int i = 0; i < n - len; i++) {
            int j = len+i;
            if(s[i] == s[j]) {
                int low = i+1,high = j-1;
                while(low<= high && s[low] != s[i]) low++;
                while(low<= high && s[high]!=s[j]) high--;
                if(low>high) dp[i][j] = dp[i+1][j-1]*2+2;
                else if(low == high) dp[i][j] = dp[i+1][j-1]*2+1;
                else dp[i][j] = dp[i+1][j-1]*2 - dp[low+1][high-1];
            }else dp[i][j] = dp[i][j-1]+dp[i+1][j] - dp[i+1][j-1];
            dp[i][j] = (dp[i][j]<0)?dp[i][j]+m:dp[i][j]%m;
        }
    }
    return dp[0][n-1];
}

int main() {
	// leetcode
	// https://leetcode.com/problems/count-different-palindromic-subsequences/
	return 0;
}

