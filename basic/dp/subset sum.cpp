#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 

// recursive
// int countSubsets(int arr[],int n,int sum){
//     if(n == 0) return sum == 0 ? 1:0;
//     return countSubsets(arr,n-1,sum)+countSubsets(arr,n-1,sum-arr[n-1]);
// }

// dp -- imp weird
int countSubsets(int arr[],int n,int sum){
    int dp[n+1][sum+1];
    
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    for (int i = 1; i <= sum; i++) dp[0][i] = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if(j< arr[i-1]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j]+dp[i][j-arr[i-1]];
        }
    }
    
    return dp[n][sum];
}

int main() {
    int n = 3, arr[]= {2, 5, 3}, sum = 5;
    cout<<countSubsets(arr, n, sum);
    return 0;
}

