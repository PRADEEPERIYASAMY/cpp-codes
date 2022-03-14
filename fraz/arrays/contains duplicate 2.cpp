#include <bits/stdc++.h>
using namespace std;

// using hash map
// bool containsNearbyDuplicate(vector<int>& nums, int k) {
//     unordered_map<int,int> mp;
//     for (int i = 0; i < nums.size(); i++) {
//         if(mp.count(nums[i]) && i - mp[nums[i]] <= k) return true;
//         mp[nums[i]] = i;
//     }
//     return false;
// }

// using set 
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> st;
    for (int i = 0; i < nums.size(); i++) {
        if(i>k) st.erase(nums[i-k-1]);
        if(st.count(nums[i])) return true;
        st.insert(nums[i]);
    }
    return false;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/contains-duplicate-ii/
    return 0;
}
