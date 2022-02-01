#include <iostream>
using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
    if(nums.empty()) return false;
    unordered_map<int,int> mp;
    mp[0] = -1;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        sum = (k == 0)? sum : sum % k;
        if(mp.count(sum)){
            if(i-mp[sum] > 1 ) return true;
        }
        else mp[sum] = i;
    }
    return false;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/house-robber/
	return 0;
}

