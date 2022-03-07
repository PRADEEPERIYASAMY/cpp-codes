#include <bits/stdc++.h>
using namespace std;

// recursion
// int sum(int arr[],int from,int to){
//     int total = 0;
//     for (int i = from; i <= to; i++) total += arr[i];
//     return total;
// }

// int partition(int arr[],int n,int k){
//     if(k == 1) return sum(arr,0,n-1);
//     if(n == 1) return arr[0];
//     int best = INT_MAX;
//     for (int i = 1; i <= n; i++) best = min(best,max(partition(arr,i,k-1),sum(arr,i,n-1)));
//     return best;
// }

// dp 
int sum(int arr[],int from,int to){
    int total = 0;
    total = accumulate(arr+from,arr+to+1,0);
    return total;
}

// we can reduce the time complexity by precomputing the sum in array instead of sum function
int partition(int arr[],int n,int k){
    int dp[k+1][n+1] = {0};
    for (int i = 0; i <= n; i++) dp[1][i] = sum(arr,0,i-1);
    for (int i = 0; i <= k; i++) dp[i][1] = arr[0];
    for (int i = 2; i <= k; i++) {
        for (int j = 2; j <= n; j++) {
            int best = INT_MAX;
            for (int p = 1; p <= j; p++) best = min(best,max(dp[i-1][p],sum(arr,p,j-1)));
            dp[i][j] = best;
        }
    }
    return dp[k][n];
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/painters-partition-problem/
    int arr[] = { 10, 20, 60, 50, 30, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << partition(arr, n, k) << endl;
    return 0;
}
