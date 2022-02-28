#include <bits/stdc++.h>
using namespace std;

int countStrings(int n,int k){
    int dp[n+1][k+1][2];
    memset(dp,0,sizeof(dp));
    dp[1][0][0] = 1;
    dp[1][0][1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j][0] = dp[i-1][j][0]+dp[i-1][j][1];
            dp[i][j][1] = dp[i-1][j][0];
            if(j-1>=0) dp[i][j][1] +=dp[i-1][j-1][1];
        }
    }
    return dp[n][k][0]+dp[n][k][1];
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/count-binary-strings-k-times-appearing-adjacent-two-set-bits/
	int n = 5, k = 2;
    cout << countStrings(n, k);
	return 0;
}

