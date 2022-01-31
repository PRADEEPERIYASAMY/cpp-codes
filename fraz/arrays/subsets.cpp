#include <iostream>
using namespace std;

//backtracking
void helper(vector<int> &nums,int ind,vector<int> &sub,vector<vector<int>> &subs){
    subs.push_back(sub);
    for (int i = ind; i < nums.size(); i++) {
        sub.push_back(nums[i]);
        helper(nums,i+1,sub,subs);
        sub.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &nums){
    vector<vector<int>> subs;
    vector<int> sub;
    helper(nums,0,sub,subs);
    return subs;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/subsets/
	return 0;
}

