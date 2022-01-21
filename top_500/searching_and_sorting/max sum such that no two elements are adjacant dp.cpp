using namespace std;
#include <bits/stdc++.h>

int FindMaxSum(vector<int> arr,int n){
    vector<int> dp(n);
    if(n == 1) return arr[0];
    if(n == 2) return max(arr[0],arr[1]);
    
    dp[0] = arr[0];
    dp[1] = arr[1];
    dp[2] = arr[0]+arr[2];
    for (int i = 3; i < n; i++) dp[i] = arr[i]+max(dp[i-2],dp[i-3]);
    return max(dp[n-1],dp[n-2]);
}

int main(){
    vector<int> arr = {5, 5, 10, 100, 10, 5};
    cout<<FindMaxSum(arr, arr.size());
    return 0;
}

