using namespace std;
#include <bits/stdc++.h>

bool helper(TreeNode *root1,TreeNode *root2){
    if(!root1||!root2) return root1 == root2;
    return root1->val == root2->val && helper(root1->left,root2->left) && helper(root1->right,root2->right);
}

bool isSubtree(TreeNode *root1,TreeNode *root2){
    if(!root1 || !root2) return root1 == root2;
    return helper(root1,root2) || isSubtree(root1->left,root2) || isSubtree(root1->right,root2);
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/subtree-of-another-tree/
    return 0;
}

