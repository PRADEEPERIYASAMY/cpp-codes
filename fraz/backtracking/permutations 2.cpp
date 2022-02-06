#include <iostream>
using namespace std;

void helper(vector<int> &nums,int level,vector<int> &cur,vector<vector<int>> &res,vector<int> &visited){
    if(level >= nums.size()){
        res.push_back(cur);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if(visited[i] == 1) continue;
        if(i> 0 && nums[i] == nums[i-1] && visited[i-1] == 0) continue;
        visited[i] = 1;
        cur.push_back(nums[i]);
        helper(nums,level+1,cur,res,visited);
        cur.pop_back();
        visited[i] = 0;
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int>> res;
    vector<int> cur,visited(nums.size(),0);
    helper(nums,0,cur,res,visited);
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/permutations-ii/
	return 0;
}

