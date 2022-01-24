using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

int ans = 0;

int dfs(TreeNode *root){
    if(!root)return 0;
    int lh = dfs(root->left);
    int rh = dfs(root->right);
    ans = max(ans,lh+rh);
    return max(lh,rh)+1;
}

int diameterOfBinaryTree(TreeNode* root) { 
    dfs(root);
    return ans;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/diameter-of-binary-tree/
    return 0;
}

