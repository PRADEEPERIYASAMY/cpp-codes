#include <iostream>
using namespace std;

int jump(vector<int>& nums) {
    int res = 0,n = nums.size(),last = 0,curReach = 0;
    for (int i = 0; i < n-1; i++) {
        curReach = max(curReach,i+nums[i]);
        if(i == last){
            last = curReach;
            res++;
            if(curReach>=n-1) break;
        }
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/jump-game-ii/
	return 0;
}

