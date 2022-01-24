using namespace std;
#include <bits/stdc++.h>

int sum;

void dfs(TreeNode *root,int L,int R){
    if(!root) return;
    if(root->val >= L && root->val <= R) sum+=root->val;
    if(root->val > L) dfs(root->left,L,R);
    if(root->val < R) dfs(root->right,L,R);
}

int rangeSumBST(TreeNode* root, int L, int R) {
    sum = 0;
    dfs(root,L,R);
    return sum;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/range-sum-of-bst/
    return 0;
}

