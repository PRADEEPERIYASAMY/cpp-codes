using namespace std;
#include <bits/stdc++.h>

bool hasPathSum(TreeNode* root, int sum) {
    if(!root) return false;
    if(!root->left && !root->right && root->val == sum) return true;
    return hasPathSum(root->left,sum-root->val) || hasPathSum(root->right,sum-root->val);
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/path-sum/
    return 0;
}

