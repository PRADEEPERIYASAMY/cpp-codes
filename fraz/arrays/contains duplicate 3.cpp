#include <bits/stdc++.h>
using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if(nums.empty() || k<1 || t<0) return false;
    set<long> st;
    for (int i = 0; i < nums.size(); i++) {
        if(i>k) st.erase(nums[i-k-1]);
        auto it = st.lower_bound((long)nums[i] - t);
        if(it != st.end() && *it - nums[i] <= t) return true;
        st.insert(nums[i]);
    }
    return false;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/contains-duplicate-iii/
    return 0;
}
