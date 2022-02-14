#include <iostream>
using namespace std;

//Suppose i < j, then we can translate yi + yj + |xi - xj| to (yi - xi) + (yj + xj)
// x+y  is const but need to maximize x - y
int findMaxValueOfEquation(vector<vector<int>>& pts, int k) {
    priority_queue<pair<int,int>> pq;
    pq.push({pts[0][1] - pts[0][0],pts[0][0]});
    int ans = INT_MIN;
    for (int i = 1; i < pts.size(); i++) {
        int sum = pts[i][0]+pts[i][1];
        while(!pq.empty() && pts[i][0] - pq.top().second > k) pq.pop();
        if(!pq.empty()) ans = max(ans,sum+pq.top().first);
        pq.push({pts[i][1] - pts[i][0],pts[i][0]});
    }
    return ans;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/max-value-of-equation/discuss/709315/C%2B%2B-Simple-Solution-using-Max-Heap
	return 0;
}

