#include <iostream>
using namespace std;

bool canJump(vector<int>& nums) {
    int n = nums.size(),maxreach = 0;
    for (int i = 0; i < n; i++) {
        if(i>maxreach || maxreach >= n-1) break;
        maxreach = max(maxreach,i+nums[i]);
    }
    return maxreach >= n-1;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/subsets/
	return 0;
}

