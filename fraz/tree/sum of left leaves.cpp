using namespace std;
#include <bits/stdc++.h>

int sum = 0;
int transverse(TreeNode *root,bool val){
    if(!root) return sum;
    transverse(root->left,true);
    transverse(root->right,false);
    if(!root->left && !root->right && val == true) sum+=root->val;
    return sum;
}

int sumOfLeftLeaves(TreeNode* root) {
    bool flag = false;
    transverse(root,flag);
    return sum;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/sum-of-left-leaves/
    return 0;
}

