#include <iostream>
using namespace std;

// STL lower_bound and upper_bound Method
// vector<int> searchRange(vector<int>& nums, int target) { 
//     vector<int> res(2,-1);
//     auto start = lower_bound(nums.begin(),nums.end(),target);
//     if(start == nums.end() || *start != target) return res;
//     else res[0] = start - nums.begin();
//     auto end = upper_bound(nums.begin(),nums.end(),target);
//     res[1] = end - nums.begin() -1;
//     return res;
// }

// Binary Search
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res(2,-1);
    if(nums.empty()) return res;
    int n = nums.size(),left = 0,right = n-1;
    while(left<right){
        int mid = left+(right - left)/2;
        if(nums[mid]<target) left = mid+1;
        else right = mid;
    }
    if(nums[left]!= target) return res;
    else res[0] = left;
    right = n -1;
    while(left<right){
        int mid = left+(right - left)/2 + 1; // bias to the right
        if(nums[mid]> target) right = mid - 1;
        else left = mid;
    }
    res[1] = right;
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
	return 0;
}

