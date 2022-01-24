using namespace std;
#include <bits/stdc++.h>

TreeNode* helper(vector<int> &nums,int l,int r){
    if(l>r) return nullptr;
    int mid = l+(r-l)/2;
    TreeNode *res = new TreeNode(nums[mid]);
    res->left = helper(nums,l,mid-1);
    res->right = helper(nums,mid+1,r);
    return res;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    int l = 0,r = nums.size()-1;
    return helper(nums,l,r);
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
    return 0;
}

