using namespace std;
#include <bits/stdc++.h>

// bool helper(TreeNode *left,TreeNode *right){
//     if(!left || !right) return left == right;
//     if(left->val != right->val) return false;
//     return helper(left->left,right->right) && helper(left->right,right->left);
// }

// bool isSymmetric(TreeNode* root) {
//     if(!root) return true;
//     return helper(root->left,root->right);
// }

//using level order transversal
bool isSymmetric(TreeNode* root) {
    if(!root) return true;
    TreeNode *left = root->left, *right = root->right;
    queue<TreeNode*> q1,q2;
    q1.push(left);
    q2.push(right);
    while(!q1.empty() && !q2.empty()){
        left = q1.front();q1.pop();
        right = q2.front();q2.pop();
        if(!left && !right) continue;
        if(!left || !right) return false;
        if(left->val != right->val) return false;
        q1.push(left->left);q1.push(left->right);
        q2.push(right->right);q2.push(right->left);
    }
    return true;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/symmetric-tree/
    return 0;
}

