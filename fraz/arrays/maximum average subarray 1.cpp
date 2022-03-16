#include <bits/stdc++.h>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    double sum = 0;
    for (int i = 0; i < k; i++) sum +=nums[i];
    double res = sum;
    for (int i = k; i < nums.size(); i++) {
        sum += nums[i] - nums[i-k];
        res = max(res,sum);
    }
    return res/k;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/maximum-average-subarray-i/
    return 0;
}
