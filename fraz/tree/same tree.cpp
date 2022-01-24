using namespace std;
#include <bits/stdc++.h>

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(!p || !q) return p == q;
    return p->val == q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/same-tree/
    return 0;
}

