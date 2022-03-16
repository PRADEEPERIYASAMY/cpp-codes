#include <bits/stdc++.h>
using namespace std;

int thirdMax(vector<int>& nums) {
    long mx1 = numeric_limits<long>::min(),mx2 = numeric_limits<long>::min(),mx3 = numeric_limits<long>::min();
    for (auto num : nums) {
        if(mx1 == num || mx2 == num || mx3 == num) continue;
        if(num >mx1){
            mx3 = mx2;
            mx2 = mx1;
            mx1 = num;
        }else if(num>mx2){
            mx3 = mx2;
            mx2 = num;
        }else if(num > mx3) mx3 = num;
    }
    return mx3 != numeric_limits<long>::min()?mx3:mx1;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/third-maximum-number/
    return 0;
}
