#include <iostream>
using namespace std;

int deleteAndEarn(vector<int>& nums) {
    vector<int> dp(10001,0);// value of nums[i] varies from 1 to 10000
    int res = 0;
    for (auto &i : nums) dp[i]++;
    for (int i = 2; i < 10001; i++) {
        dp[i] = max(dp[i-1],(dp[i]*i)+dp[i-2]);
        res = max(res,dp[i]);
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/delete-and-earn/discuss/1280691/CPP-or-Simplest-DP-solution-with-explaination
	return 0;
}

