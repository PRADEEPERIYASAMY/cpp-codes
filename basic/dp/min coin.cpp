#include <iostream>
using namespace std;
#include <bits/stdc++.h>

// recursion
// int minCoins(int arr[],int n, int val){
//     if(val == 0) return 0;
//     int res = INT_MAX;
//     for (int i = 0; i < n; i++) {
//         if(val>=arr[i]){
//             int subres = minCoins(arr,n,val-arr[i]);
//             if(subres != INT_MAX) res = min(res,subres+1);
//         }
//     }
//     return res;
// }

// dp
int minCoins(int arr[],int n, int val){
    int dp[val+1];
    for (int i = 0; i <= val; i++) dp[i] = INT_MAX;
    
    dp[0] = 0;
    
    for (int i = 1; i <= val; i++) {
        for (int j = 0; j < n; j++) {
            if(arr[j]<= i){
                int subres = dp[i -arr[j]];
                if(subres != INT_MAX) dp[i] = min(dp[i],subres+1);
            }
        }
    }
    
    return dp[val];
}

int main() {
	
    int arr[] = {3, 4, 1}, val =5, n =3;
    cout<<minCoins(arr, n, val);
    return 0;
}

