#include <iostream>
using namespace std;

int maxProduct(vector<int>& nums) {
    if(nums.empty()) return 0;
    int n = nums.size();
    vector<vector<int>> dp(n,vector<int>(2,0));
    dp[0][0] = dp[0][1] = nums[0];
    int res = nums[0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = min({nums[i],nums[i]*dp[i-1][0],nums[i]*dp[i-1][1]});
        dp[i][1] = max({nums[i],nums[i]*dp[i-1][0],nums[i]*dp[i-1][1]});
        res = max(res,dp[i][1]);
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/maximum-product-subarray/
	return 0;
}

