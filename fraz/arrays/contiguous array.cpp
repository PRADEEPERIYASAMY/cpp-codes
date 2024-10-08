#include <bits/stdc++.h>
using namespace std;

int findMaxLength(vector<int>& nums) {
    unordered_map<int,int> mp;
    mp[0] = -1;
    int res = 0,sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += (nums[i] == 1)?1:-1;
        if(mp.count(sum)) res = max(res,i - mp[sum]);
        else mp[sum] = i;
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/contiguous-array/
    return 0;
}
