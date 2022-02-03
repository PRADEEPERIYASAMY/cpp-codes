#include <iostream>
using namespace std;

// Iteration
// void flatten(TreeNode* root) { 
//     TreeNode *cur = root;
//     while(cur){
//         if(cur->left){
//             TreeNode *pre = cur->left;
//             while(pre->right) pre = pre->right;
//             pre->right = cur->right;
//             cur->right = cur->left;
//             cur->left = nullptr;
//         }
//         cur = cur->right;
//     }
// }

// recursive
void helper(TreeNode *root,TreeNode*& prev){
    if(!root) return;
    helper(root->right,prev);
    helper(root->left,prev);
    root->right = prev;
    root->left = nullptr;
    prev = root;
}

void flatten(TreeNode* root) {
    TreeNode *prev = nullptr;
    helper(root,prev);
}

int main() {
	// leetcode
	// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
	return 0;
}

