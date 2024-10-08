#include <iostream>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int left = 0,right = nums.size() - 1;
    while(left<right){
        int mid = left + (right - left)/2;
        if(nums[mid]<nums[mid+1]) left = mid+1;
        else right = mid;
    }
    return right;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/find-peak-element/
	return 0;
}

