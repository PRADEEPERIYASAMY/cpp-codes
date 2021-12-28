#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 

// recursive i = 0, j = n-1
// int MatrixChainOrder(int arr[],int i,int j){
//     if(i == j) return 0;
//     int res = INT_MAX;
    
//     for (int k = i; k <j; k++) {
//         res = min(res,MatrixChainOrder(arr,i,k)+MatrixChainOrder(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j])); 
//     }
    
//     return res;
// }

// dp
int MatrixChainOrder(int arr[],int n){
    int dp[n][n];
    for (int i=0; i<n-1; i++) dp[i][i+1] = 0;
    
    for (int g=2; g<n; g++) {
        for (int i = 0; i+g < n; i++) {
            int j = g+i;
            dp[i][j] = INT_MAX;
            for (int k = i+1; k < j; k++) {
                dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j] + (arr[i]*arr[k]*arr[j]) );
            }
        }
    }
    
    return dp[0][n-1];
}

int main() {
    int arr[] = {40, 20, 30, 10, 30}; 
	cout << "Minimum number of multiplications is "<< MatrixChainOrder(arr,5); 
    return 0;
}

