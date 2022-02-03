#include <iostream>
using namespace std;

//iteraton
// vector<vector<int>> levelOrder(TreeNode* root) {
//     vector<vector<int>> res;
//     if(!root) return res;
//     vector<int> cur;
//     queue<TreeNode*> q({root});
//     while(!q.empty()){
//         int n = q.size();
//         cur.clear();
//         for (int i = 0; i < n; i++) {
//             TreeNode *t = q.front();q.pop();
//             cur.push_back(t->val);
//             if(t->left) q.push(t->left);
//             if(t->right) q.push(t->right);
//         }
//         res.push_back(cur);
//     }
//     return res;
// }

// recursive
void helper(TreeNode *root,int level,vector<vector<int>> &res){
    if(!root) return;
    if(level == res.size()) res.push_back({});
    res[level].push_back(root->val);
    helper(root->left,level+1,res);
    helper(root->right,level+1,res);
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    helper(root,0,res);
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/binary-tree-level-order-traversal/
	return 0;
}

