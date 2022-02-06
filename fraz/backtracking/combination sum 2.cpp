#include <iostream>
using namespace std;

void helper(vector<int> &candidates,vector<vector<int>> &res,vector<int> &cur,int start,int target){
    if(target == 0){
        res.push_back(cur);
        return;
    }
    for (int i = start; i < candidates.size() && candidates[i] <= target; i++) {
        if( i != start && candidates[i] == candidates[i-1]) continue;
        cur.push_back(candidates[i]);
        helper(candidates,res,cur,i+1,target - candidates[i]);
        cur.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector<vector<int>> res;
    vector<int> cur;
    helper(candidates,res,cur,0,target);
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/combination-sum-ii/
	return 0;
}

