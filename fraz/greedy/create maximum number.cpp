#include <iostream>
using namespace std;

bool greater(const vector<int> &nums1,int i,const vector<int> &nums2,int j){
    while(i<nums1.size() && j<nums2.size() && nums1[i] == nums2[j]) i++,j++;
    return j == nums2.size() || (i<nums1.size() && nums1[i]>nums2[j]);
}

vector<int> mergeVector(const vector<int> &nums1,const vector<int> &nums2){
    int i = 0,j = 0, m = nums1.size(),n = nums2.size();
    vector<int> res;
    while(i<m || j<n) res.push_back(greater(nums1,i,nums2,j)?nums1[i++]:nums2[j++]);
    return res;
}

vector<int> maxVector(const vector<int>&nums,int k){
    int need_to_del = nums.size()-k;
    vector<int> res;
    for (auto &i : nums) {
        while(need_to_del && !res.empty() && res.back()<i) res.pop_back(),need_to_del--;
        res.push_back(i);
    }
    res.resize(k);
    return res;
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    int m = nums1.size(),n = nums2.size();
    vector<int> res;
    for (int i = max(0,k-n); i <= min(k,m); i++) {
        vector<int> vec1 = maxVector(nums1,i),vec2 = maxVector(nums2,k-i);
        vector<int> merge = mergeVector(vec1,vec2);
        if(greater(merge,0,res,0)) res = merge;
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/create-maximum-number/
	return 0;
}

