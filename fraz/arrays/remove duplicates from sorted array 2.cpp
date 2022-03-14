#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if(n<= 2) return n;int pos = 2;
    for (int i = 2; i < n; i++) if(nums[pos-2] != nums[i]) nums[pos++] = nums[i];
    return pos;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
    return 0;
}
