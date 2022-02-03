#include <iostream>
using namespace std;

// void helper(TreeNode* root,TreeNode *&pre,TreeNode *&first,TreeNode *&second){
//     if(!root) return;
//     helper(root->left,pre,first,second);
//     if(pre && pre->val >= root->val){
//         if(!first) first = pre;
//         if(first) second = root;
//     }
//     pre = root;
//     helper(root->right,pre,first,second);
// }

// void recoverTree(TreeNode* root) {
//     TreeNode *pre = nullptr,*first = nullptr,* second = nullptr;
//     helper(root,pre,first,second);
//     swap(first->val,second->val);
// }

void recoverTree(TreeNode* root) {
    TreeNode *pre = nullptr,*first = nullptr,*second = nullptr;
    stack<TreeNode*> st;
    TreeNode *cur = root;
    while(cur || !st.empty()){
        while(cur){
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();st.pop();
        if(pre && pre->val > cur->val){
            if(!first) first =pre;
            if(first) second = cur;
        }
        pre = cur;
        cur = cur->right;
    }
    swap(first->val,second->val);
}

int main() {
	// leetcode
	// https://leetcode.com/problems/recover-binary-search-tree/
	return 0;
}

