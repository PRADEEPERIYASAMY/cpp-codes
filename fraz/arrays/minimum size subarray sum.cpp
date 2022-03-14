#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int s, vector<int>& nums) {
    int n = nums.size(), start = 0, sum = 0, minLen = INT_MAX;
    for (int i = 0; i < n; ++i) {
        sum += nums[i];
        while (sum >= s) {
            minLen = min(minLen, i - start + 1);
            sum -= nums[start++];
        }
    }
    return minLen == INT_MAX ? 0 : minLen;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/minimum-size-subarray-sum/
    return 0;
}
