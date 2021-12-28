#include <iostream>
using namespace std;
#include <bits/stdc++.h>

// infinite coin of each type is available
// recursive

// int getCount(int coins[],int n,int sum){
//     if(sum == 0) return 1; // dont pick any coin is an option
//     if(n == 0) return 0; // still sum is there
    
//     int res = getCount(coins,n-1,sum);
//     if(coins[n-1]<=sum) res+=getCount(coins,n,sum-coins[n-1]);
    
//     return res;
// }

int getCount(int coins[],int n,int sum){
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
	
	int coins[]={1, 2, 3}, sum=4, n=3;
	cout<<getCount(coins, n, sum);
	return 0;
}

