#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 

// recursive -1
// int subSol(int arr[],int i, int j, int sum){
//     if(i+1 == j) return max(arr[i],arr[j]);
//     else return max(sum- subSol(arr,i+1,j,sum-arr[i]),sum- subSol(arr,i,j-1,sum-arr[j]));
// }

// int sol(int arr[],int n){
//     int sum = 0;
//     for (int i = 0; i < n; i++) sum+=arr[i];
    
//     return subSol(arr,0,n-1,sum);
// }

// recursion -2  max for user && min for opponent
// int sol(int arr[],int i,int j){
//     if(i+1 == j) return max(arr[i],arr[j]);
//     return max(
//         arr[i]+min(sol(arr,i+2,j),sol(arr,i+1,j-1)),
//         arr[j]+min(sol(arr,i,j-2),sol(arr,i+1,j-1))
//         );
// }

// dp
int sol(int arr[],int n){
    int dp[n][n];
    for (int i = 0; i <n-1; i++) dp[i][i+1] = max(arr[i],arr[i+1]); // diagonal fill after center is sufficient
    for (int g = 3; g <n; g+=2) {
        for (int i = 0; i+g <n; i++) {
            int j = i+g;
            dp[i][j] = max(
                arr[i]+min(dp[i+2][j],dp[i+1][j-1]),
                arr[j]+min(dp[i][j-2],dp[i+1][j-1])
                );
        }
    }
    return dp[0][n-1];
}

int main() {
    
    int n = 4;
    int arr[] = { 8, 15, 3, 7 };
    //cout<<sol(arr, n);
    //cout<<sol(arr, 0,n-1);
    cout<<sol(arr, n);
    return 0;
}

