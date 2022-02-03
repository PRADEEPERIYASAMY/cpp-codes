#include <iostream>
using namespace std;

// Inorder Traversal Iteration with Stack
// int kthSmallest(TreeNode* root, int k) {
//     TreeNode *cur = root;
//     stack<TreeNode*> st;
//     int n = k;
//     while(cur || !st.empty()){
//         while(cur){
//             st.push(cur);
//             cur = cur->left;
//         }
//         cur = st.top();st.pop();
//         if(--n == 0) return cur->val;
//         cur = cur->right;
//     }
//     return -1;
// }

// Inorder Traversal Recursion
void helper(TreeNode *root,int &n,int &res){
    if(!root) return;
    helper(root->left,n,res);
    if(--n == 0){
        res = root->val;
        return;
    }
    helper(root->right,n,res);
}

int kthSmallest(TreeNode* root, int k) {
    int n = k,res = -1;
    helper(root,n,res);
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
	return 0;
}

