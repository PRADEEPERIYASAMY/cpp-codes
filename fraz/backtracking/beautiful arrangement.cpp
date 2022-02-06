#include <iostream>
using namespace std;

int helper(vector<int> &nums,vector<int> &vis,int index,int n){
    if(index == n+1) return 1;
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
        if(!vis[nums[i]] && (nums[i]%index == 0 || index%nums[i] == 0)){
            vis[nums[i]] = 1;
            res+=helper(nums,vis,index+1,n);
            vis[nums[i]] = 0;
        }
    }
    return res;
}

int countArrangement(int n){
    vector<int> nums,vis(n+1,0);
    for (int i = 1; i <= n; i++) nums.push_back(i);
    int ans = helper(nums,vis,1,n);
    return ans;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/beautiful-arrangement/discuss/1423458/C%2B%2B-Backtracking
	return 0;
}

