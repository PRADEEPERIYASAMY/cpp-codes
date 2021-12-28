#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 

// recursive
// int maxSum(int arr[],int n){
//     if(n == 1) return arr[0];
//     if(n == 2) return max(arr[0],arr[1]);
//     return max(maxSum(arr,n-1),maxSum(arr,n-2)+arr[n-1]);
// }

// dp
// int maxSum(int arr[],int n){
//     if(n == 0) return arr[0];
//     int dp[n+1];
//     dp[1] = arr[0];
//     dp[2] = max(arr[0],arr[1]);
    
//     for (int i = 3; i <= n; i++) dp[i] = max(dp[i-1],dp[i-2]+arr[i-1]);
    
//     return dp[n];
// }

// space optimization can be done using 2 varables instead of array

int maxSum(int arr[], int n)
{
	if(n==0) return arr[0];
	int prev_prev = arr[0];
	int prev = max(arr[0], arr[1]);
	int res = prev;
	for(int i=3; i<=n; i++){
		res = max(prev, prev_prev + arr[i-1]);
		prev_prev = prev;
		prev = res;
	}
	return res;
}


int main() {
    int n = 5, arr[]= {10, 20, 30, 40, 50};
    cout<<maxSum(arr, n);
    return 0;
}

