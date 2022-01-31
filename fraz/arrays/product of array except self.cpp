using namespace std;
#include <bits/stdc++.h>

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size(),left = 1,right = 1;
    vector<int> res(n,1);
    for (int i = 0; i < n; i++) {
        res[i] *=left;
        left *=nums[i];
    }
    for (int i = n-1; i >= 0; i--) {
        res[i] *= right;
        right *= nums[i];
    }
    return res;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/product-of-array-except-self/
    return 0;
}

