#include <iostream>
using namespace std;

int helper(TreeNode *root,unordered_map<TreeNode*,int>& memo){
    if(!root) return 0;
    if(memo.count(root)) return memo[root];
    int val = root->val;
    if(root->left) val+=helper(root->left->left,memo)+helper(root->left->right,memo);
    if(root->right) val+=helper(root->right->left,memo)+helper(root->right->right,memo);
    return memo[root] = max(val,helper(root->left,memo)+helper(root->right,memo));
}

int rob(TreeNode *root){
    unordered_map<TreeNode*,int> memo;
    return helper(root,memo);
}

int main() {
	// leetcode
	// https://leetcode.com/problems/house-robber-iii/
	return 0;
}

