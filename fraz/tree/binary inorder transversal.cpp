using namespace std;
#include <bits/stdc++.h>

// void helper(TreeNode *root,vector<int>& res){
//     if(!root) return;
//     helper(root->left,res);
//     res.push_back(root->val);
//     helper(root->right,res);
// }

// vector<int> inorderTraversal(TreeNode* root) {
//     vector<int> res;
//     helper(root,res);
//     return res;
// }

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while(cur || !st.empty()){
        while(cur){
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();st.pop();
        res.push_back(cur->val);
        cur = cur->right;
    }
    return res;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/binary-tree-inorder-traversal/
    return 0;
}

