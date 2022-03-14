#include <bits/stdc++.h>
using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;
    if(nums.empty()) return res;
    int next = nums.front();
    for (int i = 0; i < nums.size(); i++) {
        while(i+1<nums.size() && nums[i]+1 == nums[i+1]) i++;
        string tmp;
        if(nums[i] != next) tmp = to_string(next)+"->"+to_string(nums[i]);
        else tmp = to_string(next);
        res.push_back(tmp);
        if(i!=nums.size()-1) next = nums[i+1];
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/summary-ranges/
    return 0;
}
