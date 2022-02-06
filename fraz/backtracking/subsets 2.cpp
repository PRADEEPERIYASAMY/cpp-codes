#include <iostream>
using namespace std;

void helper(vector<vector<int>> &res,vector<int> &nums,vector<int> &cur,int start){
    res.push_back(cur);
    for (int i = start; i < nums.size(); i++) {
        if( i != start && nums[i] == nums[i - 1]) continue;
        cur.push_back(nums[i]);
        helper(res,nums,cur,i+1);
        cur.pop_back();
    }
}  

vector<vector<int>> subsetsWithDup(vector<int> &nums){
    sort(nums.begin(),nums.end());
    vector<vector<int>> res;
    vector<int> cur;
    helper(res,nums,cur,0);
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/subsets-ii/discuss/30164/Accepted-10ms-c%2B%2B-solution-use-backtracking-only-10-lines-easy-understand.
	return 0;
}

