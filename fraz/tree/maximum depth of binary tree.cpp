using namespace std;
#include <bits/stdc++.h>

int maxDepth(TreeNode* root) { 
    if(!root) return 0;
    return max(maxDepth(root->left),maxDepth(root->right))+1;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/maximum-depth-of-binary-tree/
    return 0;
}

