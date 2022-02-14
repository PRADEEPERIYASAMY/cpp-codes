#include <iostream>
using namespace std;

// Dynamic Programming
int numDistinct(string s, string t) {
    int m = s.size(),n = t.size();
    vector<vector<unsigned long long>> dp(n+1,vector<unsigned long long>(m+1,0));
    for (int j = 0; j <=m; j++) dp[0][j] = 1;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) dp[i][j] = dp[i][j-1]+(s[j-1] == t[i-1]?dp[i-1][j-1]:0);
    return (int)dp[n][m];
}

int main() {
	// leetcode
	// https://leetcode.com/problems/distinct-subsequences/
	return 0;
}

