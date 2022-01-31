#include <iostream>
using namespace std;

void helper(vector<int> &candidates,vector<vector<int>> &res,vector<int> &cur,int start,int target){
    if(target<0) return;
    else if(target == 0) res.push_back(cur);
    else{
        for (int i = start; i < candidates.size(); i++) {
            cur.push_back(candidates[i]);
            helper(candidates,res,cur,i,target- candidates[i]);
            cur.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> cur;
    helper(candidates,res,cur,0,target);
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/combination-sum/
	return 0;
}

