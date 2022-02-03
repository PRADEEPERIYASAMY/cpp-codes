#include <iostream>
using namespace std;

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root || root == p|| root == q) return root;
    TreeNode *left = lowestCommonAncestor(root->left,p,q);
    TreeNode *right = lowestCommonAncestor(root->right,p,q);
    if(left && right) return root;
    else return left?left:right;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
	return 0;
}

