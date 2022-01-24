using namespace std;
#include <bits/stdc++.h>

int diff = INT_MAX;
TreeNode *prev = nullptr;

void dfs(TreeNode *root){
    if(root->left) dfs(root->left);
    if(prev) diff = min(diff,abs(prev->val-root->val));
    prev = root;
    if(root->right) dfs(root->right);
}

int getMinimumDifference(TreeNode *root) {
    dfs(root);
    return diff;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/minimum-absolute-difference-in-bst/
    return 0;
}

