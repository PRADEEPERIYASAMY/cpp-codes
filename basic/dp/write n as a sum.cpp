#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

// dp
// similar to coin change
int countWays(int coins[],int n,int sum){
    int dp[sum+1][n+1];
    for (int i = 0; i <= sum; i++) dp[i][0] = 0;
    for (int i = 0; i <= n; i++) dp[0][i] = 1;
    
    for (int i = 1; i <= sum; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i][j-1];
            if(coins[j-1]<= i) dp[i][j]+=dp[i-coins[j-1]][j];
        }
    }
    
    return dp[sum][n];
}
 
int main() {
	int n = 7;
	int arr[] = {1,2,3,4,5,6}; // possible values
    cout << countWays(arr,n-1,n);
    return 0;
}

