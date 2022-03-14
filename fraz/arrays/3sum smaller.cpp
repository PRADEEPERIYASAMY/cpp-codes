#include <bits/stdc++.h>
using namespace std;

int threeSumSmaller(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int res = 0,n = nums.size();
    for (int i = 0; i < n-2; i++) {
        int l = i+1,r = n-1;
        while(l<r){
            int sum = nums[i]+nums[l]+nums[r];
            if(sum<target) res+=(r - l),l++;
            else r--;
        }
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/3sum-smaller/
    return 0;
}
