#include <bits/stdc++.h>
using namespace std;

int findLongestRepeatingSubSeq(string str){
    int n = str.size();
    int dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(str[i-1] == str[j-1] && i!=j) dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp[n][n];
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/longest-repeating-subsequence/
	string str = "aabb";
    cout << "The length of the largest subsequence that repeats itself is : "<< findLongestRepeatingSubSeq(str);
    return 0;
}
