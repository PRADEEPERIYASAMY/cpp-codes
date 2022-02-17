#include <iostream>
using namespace std;

// nlogn
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    priority_queue<pair<int,int>> pq;
    vector<int> res;
    for (auto num : nums) mp[num]++;
    for (auto &it : mp) pq.push({it.second,it.first});
    for (int i = 0; i < k; i++) {
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;
}

// nlogk
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> res;
    for (auto num : nums) mp[num]++;
    for (auto &it : mp) {
        pq.push({it.second,it.first});
        if(pq.size()>k) pq.pop();
    }
    while(!pq.empty()){
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/top-k-frequent-elements/
	return 0;
}

