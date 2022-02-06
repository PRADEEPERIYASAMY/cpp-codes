#include <iostream>
using namespace std;

void helper(vector<vector<int>> &res,vector<int>&cur,int n,int k,int start){
    if(cur.size()>=k){
        res.push_back(cur);
        return;
    }
    for (int i = start; i <= n; i++) {
        cur.push_back(i);
        helper(res,cur,n,k,i+1);
        cur.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> cur;
    helper(res,cur,n,k,1);
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/combinations/
	return 0;
}

