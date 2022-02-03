#include <iostream>
using namespace std;

int ans = 0;
void pre(TreeNode *root,int max){
    if(!root) return;
    if(root->val >= max){ans++;max = root->val;}
    pre(root->left,max);
    pre(root->right,max);
}

int goodNodes(TreeNode* root) {
    pre(root,INT_MIN);
    return ans;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/count-good-nodes-in-binary-tree/
	return 0;
}

