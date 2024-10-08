#include <iostream>
using namespace std;

// vector<int> findDuplicates(vector<int>& nums) {
//     vector<int> res;
//     for (int i = 0; i < nums.size(); i++) {
//         int idx = abs(nums[i])-1;
//         if(nums[idx]<0) res.push_back(idx+1);
//         nums[idx] = -nums[idx];
//     }
//     return res;
// }

// vector<int> findDuplicates(vector<int> &nums){
//     vector<int> res;
//     for (int i = 0; i < nums.size(); i++) if(nums[i] != nums[nums[i]-1]) swap(nums[i],nums[nums[i]-1]),i--;
//     for (int i = 0; i < nums.size(); i++) if(nums[i]!=i+1) res.push_back(nums[i]);
//     return res;
// }

vector<int> findDuplicates(vector<int> &nums){
    vector<int> res;
    int n = nums.size();
    for (int i = 0; i < n; i++) nums[(nums[i]-1)%n] +=n;
    for (int i = 0; i < n; i++) if(nums[i]>2*n) res.push_back(i+1);
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/find-all-duplicates-in-an-array/
	return 0;
}

