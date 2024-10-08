#include <iostream>
using namespace std;

// vector<vector<int>> subsets(vector<int>& nums) {
//     vector<vector<int>> subs;
//     vector<int> sub;
//     subsets(nums,0,sub,subs);
//     return subs;
// }

// void subsets(vector<int> &nums,int i,vector<int> &sub,vector<vector<int>> &subs){
//     subs.push_back(sub);
//     for (int j = i; j < nums.size() ; j++) {
//         sub.push_back(nums[j]);
//         subsets(nums,j+1,sub,subs);
//         sub.pop_back();
//     }
// }

// vector<vector<int>> subsets(vector<int> &nums){
//     vector<vector<int>> subs = {{}};
//     for (auto &num : nums) {
//         int n = subs.size();
//         for (int i = 0; i < n; i++) {
//             subs.push_back(subs[i]);
//             subs.back().push_back(num);
//         }
//     }
//     return subs;
// }

vector<vector<int>> subsets(vector<int> &nums){
    int n = nums.size(),p = 1<<n;
    vector<vector<int>> subs(p);
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < n; j++) {
            if((i>>j) & 1) subs[i].push_back(nums[j]);
        }
    }
    return subs;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/subsets/discuss/27278/C%2B%2B-RecursiveIterativeBit-Manipulation
	return 0;
}

