#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int res = 0,cur = 0;
    for (auto &num : nums) {
        if(num == 1) res = max(res,++cur);
        else cur = 0;
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/max-consecutive-ones/
    return 0;
}
