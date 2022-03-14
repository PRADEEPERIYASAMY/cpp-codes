#include <bits/stdc++.h>
using namespace std;

int maximumGap(vector<int>& nums) {
    int n = nums.size();
    if(n<2) return 0;
    int mx = *max_element(nums.begin(),nums.end());
    int mn = *min_element(nums.begin(),nums.end());
    int gap = max(1,(mx - mn)/(n-1));
    int m = (mx - mn)/gap+1;
    vector<vector<int>> buckets(m);
    for (auto &num : nums) {
        int idx = (num - mn)/gap;
        if(buckets[idx].empty()) buckets[idx] = vector<int>(2,num);
        else{
            buckets[idx][0] = min(buckets[idx][0],num);
            buckets[idx][1] = max(buckets[idx][1],num);
        }
    }
    int prev = 0;
    gap = 0;
    for (int i = 0; i < m; i++) {
        if(buckets[i].empty()) continue;
        gap = max(gap,buckets[i][0] - buckets[prev][1]);
        prev = i;
    }
    return gap;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/maximum-gap/
	//https://leetcode.com/problems/maximum-gap/discuss/1240543/Python-Bucket-sort-explained
    return 0;
}
