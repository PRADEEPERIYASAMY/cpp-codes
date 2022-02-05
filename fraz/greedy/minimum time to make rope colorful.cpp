#include <iostream>
using namespace std;

int minCost(string s, vector<int>& cost) {
    int res = 0,max_cost = 0,n = s.size();
    for (int i = 0; i < n; i++) {
        if(i>0 && s[i]!= s[i-1]) max_cost = 0;
        res +=min(cost[i],max_cost);
        max_cost = max(max_cost,cost[i]);
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/discuss/831588/JavaC%2B%2BPython-Straight-Forward
	return 0;
}

