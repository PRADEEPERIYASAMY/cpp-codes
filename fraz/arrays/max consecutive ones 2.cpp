#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int res = 0,zero_count = 0,begin = 0,end = 0;
    while(end <nums.size()){
        if(nums[end++] == 0) zero_count++;
        while(zero_count>1){
            if(nums[begin++] == 0) zero_count--;
        }
        res = max(res,end - begin);
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/max-consecutive-ones-ii/
    return 0;
}
