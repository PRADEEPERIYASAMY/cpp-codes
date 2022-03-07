#include <bits/stdc++.h>
using namespace std;

int countWays(int n,int m){
    int dp[n+1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        if(i>m) dp[i] = dp[i-1]+dp[i-m];
        else if(i<m || i == 1) dp[i] = 1;
        else dp[i] = 2;
    }
    return dp[n];
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/count-number-ways-tile-floor-size-n-x-m-using-1-x-m-size-tiles/
    int n = 7, m = 4;
    cout << "Number of ways = "<<countWays(n, m);
    return 0;
}
