using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

// TreeNode* invertTree(TreeNode* root) {
//     if(!root) return root;
//     TreeNode *temp = invertTree(root->left);
//     root->left = invertTree(root->right);
//     root->right = temp;
//     return root;
// }


TreeNode* invertTree(TreeNode* root) {
    if(!root) return root;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode *temp = q.front();q.pop();
        swap(temp->left,temp->right);
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    return root;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/invert-binary-tree/
    return 0;
}

