#include <bits/stdc++.h>
using namespace std;

bool increasingTriplet(vector<int>& nums) {
    int c1 = INT_MAX,c2 = INT_MAX;
    for (auto num : nums) {
        if(num <= c1) c1 = num;
        else if(num <= c2) c2 = num;
        else return true;
    }
    return false;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/
    return 0;
}
