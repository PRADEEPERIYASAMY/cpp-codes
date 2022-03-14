#include <bits/stdc++.h>
using namespace std;

string getString(int num1,int num2){
    return num1 == num2 ? to_string(num1): to_string(num1)+"->"+to_string(num2);
}

vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    vector<string> res;
    long next = lower;
    for (int i = 0; i < nums.size(); i++) {
        if(nums[i]<next) continue;
        if(nums[i] == next) next++;
        else{
            res.push_back(getString(next,nums[i]-1));
            next = (long) nums[i]+1;
        }
    }
    if(next<=upper) res.push_back(getString(next,upper));
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/missing-ranges/
    return 0;
}
