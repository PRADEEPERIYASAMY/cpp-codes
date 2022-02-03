#include <iostream>
using namespace std;

//iteration
// vector<int> rightSideView(TreeNode* root) {
//     vector<int> res;
//     if(!root) return res;
//     queue<TreeNode*> q({root});
//     while(!q.empty()){
//         for (int i = q.size()-1; i >= 0; i--) {
//             TreeNode *t = q.front();q.pop();
//             if(t->left) q.push(t->left);
//             if(t->right) q.push(t->right);
//             if(i == 0) res.push_back(t->val);
//         }
//     }
//     return res;
// }

// recursion

void helper(TreeNode *root,int level,vector<int> &res){
    if(!root) return;
    if(res.size() == level) res.push_back(root->val);
    helper(root->right,level+1,res);
    helper(root->left,level+1,res);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    helper(root,0,res);
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/binary-tree-right-side-view/
	return 0;
}

