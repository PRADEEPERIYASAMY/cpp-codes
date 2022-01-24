using namespace std;
#include <bits/stdc++.h>

void helper(TreeNode *root,string cur,vector<string> &res){
    if(!root->left && !root->right){
        cur+=to_string(root->val);
        res.push_back(cur);
        return;
    }
    cur+=to_string(root->val)+"->";
    if(root->left) helper(root->left,cur,res);
    if(root->right) helper(root->right,cur,res);
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    if(!root) return res;
    string cur;
    helper(root,cur,res);
    return res;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/binary-tree-paths/
    return 0;
}

