#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
    if(nums.empty() || nums[0].empty()) return nums;
    int m = nums.size(),n = nums[0].size();
    if(m*n != r*c) return nums;
    vector<vector<int>> res(r,vector<int>(c,0));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int tmp = i*c + j;
            res[i][j] = nums[tmp/n][tmp%n];
        }
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/reshape-the-matrix/
    return 0;
}
