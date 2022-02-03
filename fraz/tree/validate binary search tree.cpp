#include <iostream>
using namespace std;

//iteration
// bool isValidBST(TreeNode* root) {
//     if(!root) return true;
//     stack<TreeNode*>st;
//     TreeNode* prev = nullptr;
//     while(root || !st.empty()){
//         while(root){
//             st.push(root);
//             root = root->left;
//         }
//         root = st.top();st.pop();
//         if(prev && root->val <= prev->val) return false;
//         prev = root;
//         root = root->right;
//     }
//     return true;
// }

//recursion
// bool helper(TreeNode *root,TreeNode *&pre){
//     if(!root) return true;
//     if(!helper(root->left,pre)) return false;
//     if(pre){
//         if(root->val<= pre->val) return false;
//     }
//     pre= root;
//     return helper(root->right,pre);
// }

// bool isValidBST(TreeNode* root) {
//     TreeNode *pre = nullptr;
//     return helper(root,pre);
// }

bool isValidBST(TreeNode* root) {
    if(!root) return true;
    TreeNode *cur,*pre = nullptr,*parent = nullptr;
    bool res = true;
    while(cur){
        if(!cur->left){
            if(parent && parent->val >= cur->val) res = false;
            parent = cur;
            cur = cur->right;
        }else{
            pre = cur->left;
            while(pre->right && pre->right != cur) pre = pre->right;
            if(!pre->right){
                pre->right = cur;
                cur = cur->left;
            }else{
                pre->right = nullptr;
                if(parent->val >= cur->val) res = false;
                parent = cur;
                cur = cur->right;
            }
        }
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/validate-binary-search-tree/
	return 0;
}

