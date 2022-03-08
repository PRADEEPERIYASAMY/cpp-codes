#include <bits/stdc++.h>
using namespace std;

// recursive
// int minRemovals(int arr[],int l,int h){
//     if(l>=h) return 0;
//     int mn = *min_element(arr+l,arr+h+1);
//     int mx = *max_element(arr+l,arr+h+1);
//     if(2*mn>mx) return 0;
//     return min(minRemovals(arr,l+1,h),minRemovals(arr,l,h-1))+1;
// }

int minRemovals(int arr[],int n){
    int dp[n][n],gap,i,j,mx,mn;
    for (gap = 0; gap <n; gap++) {
        for (i = 0,j=gap; j < n; i++,j++) {
            mn = *min_element(arr+i,arr+j+1);
            mx = *max_element(arr+i,arr+j+1);
            dp[i][j] = (2*mn>mx)?0:min(dp[i+1][j],dp[i][j-1])+1;
        }
    }
    return dp[0][n-1];
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/remove-minimum-elements-either-side-2min-max/
	int arr[] = {4, 5, 100, 9, 10, 11, 12, 15, 200};
    int n = sizeof(arr)/sizeof(arr[0]);
    //cout << minRemovals(arr, 0, n-1);
    cout << minRemovals(arr, n);
    return 0;
}
