#include <iostream>
using namespace std;

// vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//     if(nums.empty() || k<= 0) return {};
//     vector<int> res;
//     priority_queue<pair<int,int>> pq;
//     for (int i = 0; i < nums.size(); i++) {
//         while(!pq.empty() && pq.top().second<=i-k) pq.pop();
//         pq.push({nums[i],i});
//         if(i>=k-1) res.push_back(pq.top().first);
//     }
//     return res;
// }

// linear time
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if(nums.empty() || k<= 0) return {};
    vector<int> res;
    deque<int> dp;
    for (int i = 0; i < nums.size(); i++) {
        while(!dp.empty() && dp.front() == i-k) dp.pop_front();
        while(!dp.empty() && nums[dp.back()]<nums[i]) dp.pop_back();
        dp.push_back(i);
        if(i>=k-1) res.push_back(nums[dp.front()]);
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/sliding-window-maximum/
	return 0;
}

