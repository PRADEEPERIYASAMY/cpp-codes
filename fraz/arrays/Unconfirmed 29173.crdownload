#include <bits/stdc++.h>
using namespace std;

int triangleNumber(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int res = 0,n = nums.size();
    for (int i = n-1; i >= 2; i--) {
        int l = 0,r = i-1;
        while(l<r){
            if(nums[l]+nums[r]>nums[i]) res+=(r-l),r--;
            else l++;
        }
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/valid-triangle-number/
    return 0;
}
