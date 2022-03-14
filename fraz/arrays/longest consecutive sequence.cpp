#include <bits/stdc++.h>
using namespace std;

// using hash set 
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> st(nums.begin(),nums.end());
    int res = 0;
    for (auto &i : nums) {
        if(!st.count(i)) continue;
        st.erase(i);
        int prev = i-1,next = i+1;
        while(st.count(prev)) st.erase(prev--);
        while(st.count(next)) st.erase(next++);
        res = max(res,next - prev -1);
    }
    return res;
}

// using hashmap
int longestConsecutive(vector<int>& nums) {
    unordered_map<int,int> mp;
    int res = 0;
    for (auto &i : nums) {
        if(mp.count(i)) continue;
        int left = mp.count(i-1)?mp[i-1]:0;
        int right = mp.count(i+1)?mp[i+1]:0;
        int sum = left+right+1;
        mp[i] = sum;
        res = max(res,sum);
        mp[i-left] = sum;
        mp[i+right] = sum;
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/longest-consecutive-sequence/
    return 0;
}
