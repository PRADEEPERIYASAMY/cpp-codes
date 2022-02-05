#include <iostream>
using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size(),res = 0;
    vector<int> nums(n,1);
    for (int i = 0; i < n-1; i++) if(ratings[i+1]>ratings[i]) nums[i+1] = nums[i]+1;
    for (int i = n-1; i >0 ; i--) if(ratings[i-1]>ratings[i]) nums[i-1] = max(nums[i-1],nums[i]+1);
    res = accumulate(nums.begin(),nums.end(),0);
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/candy/
	return 0;
}

