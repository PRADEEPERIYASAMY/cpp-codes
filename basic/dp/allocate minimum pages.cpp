#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 

// recursion

int sum(int arr[],int i,int j){
    int sum = 0;
    for (int x = i; x <= j; x++) sum+=arr[x];
    return sum;
}

// int minPages(int arr[],int n,int k){
//     if(k == 1) return sum(arr,0,n-1);
//     if(n == 1) return arr[0];
//     int res = INT_MAX;
//     for (int i = 1; i < n; i++) {
//         res = min(res,max(minPages(arr,i,k-1),sum(arr,i,n-1)));
//     }
//     return res;
// }

// dp
int minPages(int arr[],int n,int k){
    int dp[k+1][n+1];
    for (int i = 1; i <= n; i++) dp[1][i] = sum(arr,0,i-1);
    for (int i = 1; i <= k; i++) dp[i][1] = arr[0];
    
    for (int i = 2; i <=k; i++) {
        for (int j = 2; j <= n; j++) {
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j],max(dp[i-1][k],sum(arr,k,j-1)));
            }
        }
    }
    
    return dp[k][n];
}

int main() {
    int arr[]={10,20,10,30};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=2;
    cout<<minPages(arr,n,k);
    return 0;
}

