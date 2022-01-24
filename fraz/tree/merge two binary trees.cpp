using namespace std;
#include <bits/stdc++.h>

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if(t1 && t2) {
        TreeNode* res = new TreeNode(t1->val+t2->val);
        res->left = mergeTrees(t1->left,t2->left);
        res->right = mergeTrees(t1->right,t2->right);
        return res;
    }else return t1?t1:t2;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/merge-two-binary-trees/
    return 0;
}

