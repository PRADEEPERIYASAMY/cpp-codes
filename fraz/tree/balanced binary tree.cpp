using namespace std;
#include <bits/stdc++.h>

int helper(TreeNode* root) {
    if(!root) return 0;
    int lh = helper(root->left);
    if(lh == -1) return -1;
    int rh = helper(root->right);
    if(rh == -1) return -1;
    if(abs(lh-rh)>1) return -1;
    return max(lh,rh)+1;
}

bool isBalanced(TreeNode* root) {
    return helper(root)!=-1;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/balanced-binary-tree/
    return 0;
}

