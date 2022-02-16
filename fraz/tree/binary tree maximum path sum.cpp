#include <iostream>
using namespace std;

int helper(TreeNode* root,int &res){
    if(!root) return 0;
    int left = max(0,helper(root->left,res));
    int right = max(0,helper(root->right,res));
    res = max(res,left+root->val+right)
    return max(left,right)+root->val;
}

int maxPathSum(TreeNode* root) {
    int res = INT_MIN;
    helper(root,res);
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/binary-tree-maximum-path-sum/
	return 0;
}

