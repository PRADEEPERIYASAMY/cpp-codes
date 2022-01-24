using namespace std;
#include <bits/stdc++.h>

// TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//     if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left,p,q);
//     else if(root->val <p->val && root->val <q->val) return lowestCommonAncestor(root->right,p,q);
//     return root;
// }

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* cur = root;
    while(cur){
        if(cur->val > p->val && cur->val > q->val) cur = cur->left;
        else if(cur->val < p->val && cur->val <q->val) cur = cur->right;
        else break;
    }
    return cur;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
    return 0;
}

