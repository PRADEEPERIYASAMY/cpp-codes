#include <bits/stdc++.h>
using namespace std;

int maxDistance(vector<vector<int>>& arrays) {
    int res = INT_MIN,curMax = arrays[0].back(),curMin = arrays[0].front();
    for (int i = 1; i < arrays.size(); i++) {
        res = max({res,abs(arrays[i].front() - curMax),abs(arrays[i].back() - curMin)});
        curMax = max(curMax,arrays[i].back());
        curMin = min(curMin,arrays[i].front());
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/maximum-distance-in-arrays/
    return 0;
}
