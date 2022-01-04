#include<bits/stdc++.h>
using namespace std;

//recursion
// int minJumps(int arr[],int n){
//     if(n == 1) return 0;
//     int res = INT_MAX;
//     for (int i = n-2; i >=0; i--) {
//         if(i+arr[i]>=n-1){
//             int sub_res = minJumps(arr,i+1);
//             if(sub_res != INT_MAX) res = min(res,sub_res+1);
//         }
//     }
//     return res;
// }

int minJumps(int arr[],int n){
    int dp[n];
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < i; j++) {
            if(j+arr[j]>=i && dp[j] != INT_MAX){
                dp[i] = min(dp[i],dp[j]+1);
            }
        }
    }
    return dp[n-1];
}

int main() {
    int arr[] = { 1, 3, 6, 3, 2,3, 6, 8, 9, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum number of jumps to";
    cout << " reach the end is " << minJumps(arr, n);
    return 0;
}

