using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

// Dynamic Programming
// int maxSubArray(vector<int>& nums) {
//     int n = nums.size();
//     vector<int> dp(n,0);
//     dp[0] = nums[0];
//     for (int i = 1; i < n; i++) dp[i] = max(dp[i-1],0)+nums[i];
//     return *max_element(dp.begin(),dp.end());
// }

// Space Optimized Dynamic Programming
int maxSubArray(vector<int>& nums) {
    int sum = 0,res = nums[0];
    for (int i = 0; i < nums.size(); i++) {
        sum+=nums[i];
        res = max(res,sum);
        sum = max(sum,0);
    }
    return res;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/maximum-subarray/
    return 0;
}

