#include <bits/stdc++.h>
using namespace std;

// using sort 
bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    for (int i = 1; i < nums.size(); i++) if(nums[i] == nums[i-1]) return true;
    return false;
}

// also can be done with set 

int main() {
	// leetcode
	// https://leetcode.com/problems/contains-duplicate/
    return 0;
}
