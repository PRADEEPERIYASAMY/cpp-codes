#include <iostream>
using namespace std;

//brute force
// int helper(TreeNode* root,int sum){
//     if(!root) return 0;
//     return (root->val == sum?1:0)+helper(root->left,sum-root->val)+helper(root->right,sum-root->val);
// }

// int pathSum(TreeNode* root, int sum) {
//     if(!root) return 0;
//     return helper(root,sum)+pathSum(root->left,sum)+pathSum(root->right,sum);
// }

int helper(TreeNode *root,int sum,int curSum,unordered_map<int,int> &mp){
    if(!root) return 0;
    curSum+=root->val;
    int res = mp[curSum-sum];
    mp[curSum]++;
    res+=helper(root->left,sum,curSum,mp)+helper(root->right,sum,curSum,mp);
    mp[curSum]--;
    return res;
}

int pathSum(TreeNode* root, int sum) {
    unordered_map<int,int> mp;
    mp[0] = 1;
    return helper(root,sum,0,mp);
}

int main() {
	// leetcode
	// https://leetcode.com/problems/binary-tree-level-order-traversal/
	return 0;
}

