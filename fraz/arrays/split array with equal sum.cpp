#include <bits/stdc++.h>
using namespace std;

bool splitArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> sums(n,0);
    sums[0] = nums[0];
    for (int i = 1; i < n; i++) sums[i] = sums[i-1]+nums[i];
    unordered_set<int> st;
    // i - left, j = mid, k = right
    for (int j = 3; j < n-3; j++) {
        st.clear();
        for (int i = 1; i < j-1; i++) {
            if(sums[i-1] == sums[j-1]-sums[i]) st.insert(sums[i-1]);
        }
        if(st.empty()) continue;
        for (int k = j+2; k < n-1; k++) {
            if(sums[n-1] - sums[k] == sums[k-1] - sums[j] && st.count(sums[k-1] - sums[j])) return true;
        }
    }
    return false;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/split-array-with-equal-sum/
    return 0;
}
