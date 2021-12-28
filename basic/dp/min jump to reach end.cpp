#include <iostream>
using namespace std;
#include <bits/stdc++.h>

// recursion
// int minJumps(int arr[], int n){
//     if(n == 1) return 0;
//     int res = INT_MAX;
//     for (int i = 0; i <= n-2; i++) {
//         if(arr[i]+i>= n-1){
//             int subres = minJumps(arr,i+1);
//             if(subres != INT_MAX) res = min(res,subres+1);
//         }
//     }
//     return res;
// }

// dp
int minJumps(int arr[], int n){
    int dp[n];
    dp[0] = 0;
    
    for (int i = 1; i <n; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < i; j++) {
            if(arr[j]+j >= i && dp[j] != INT_MAX){
                dp[i] = min(dp[j]+1,dp[i]);
            }
        }
    }
    
    return dp[n-1];
}

int main() {
	
    int arr[] = {3, 4, 2, 1, 2, 1}, n =6;
    cout<<minJumps(arr, n);
    return 0;
}

