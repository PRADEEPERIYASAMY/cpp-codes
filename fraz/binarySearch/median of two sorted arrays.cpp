#include <iostream>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(),n = nums2.size();
    if(m>n) return findMedianSortedArrays(nums2,nums1);
    int left =0,right = m;
    while(left<=right){
        int partition1 = left+(right - left)/2;
        int partition2 = (m+n+1)/2 - partition1;
        int maxLeft1 = partition1 == 0?INT_MIN:nums1[partition1-1];
        int minRight1 = partition1 == m?INT_MAX:nums1[partition1];
        int maxLeft2 = partition2 == 0?INT_MIN:nums2[partition2-1];
        int minRight2 = partition2 == n?INT_MAX:nums2[partition2];
        if(maxLeft1<=minRight2 && maxLeft2<=minRight1){
            if((m+n)%2 == 0) return (double) (max(maxLeft1,maxLeft2)+min(minRight1,minRight2))/2.0;
            else return (double)(max(maxLeft1,maxLeft2));
        }else if(maxLeft1>minRight2) right = partition1-1;
        else left = partition1+1;
    }
    return -1.0;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/median-of-two-sorted-arrays/
	return 0;
}

