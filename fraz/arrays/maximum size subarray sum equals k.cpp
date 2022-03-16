#include <bits/stdc++.h>
using namespace std;

int maxSubArrayLen(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    int res = 0,sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if(sum == k) res = i+1;
        else if(mp.count(sum - k)) res = max(res,i - mp[sum-k]);
        
        if(!mp.count(sum)) mp[sum] = i;
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/
    return 0;
}
