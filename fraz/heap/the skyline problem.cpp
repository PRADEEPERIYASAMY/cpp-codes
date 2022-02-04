#include <iostream>
using namespace std;

// Heap
vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<vector<int>> height,res;
    for (auto &i : buildings) {
        height.push_back({i[0],-i[2]});
        height.push_back({i[1],i[2]});
    }
    sort(height.begin(),height.end());
    priority_queue<int> pq;
    pq.push(0);
    unordered_map<int,int> to_del;
    int pre = 0,cur = 0;
    for (auto &h : height) {
        if(h[1]<0) pq.push(-h[1]);
        else {
            to_del[h[1]]++;
            while(!pq.empty() && to_del[pq.top()]>0){
                --to_del[pq.top()];
                pq.pop();
            }
        }
        cur = pq.top();
        if(cur != pre){
            res.push_back({h[0],cur});
            pre = cur;
        }
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/the-skyline-problem/
	return 0;
}

