#include <iostream>
using namespace std;

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(!root) return res;
    queue<TreeNode*> q({root});
    bool toRight = true;
    while(!q.empty()){
        vector<int> cur;
        for (int i = q.size()-1; i >= 0; i--) {
            TreeNode *t = q.front();q.pop();
            cur.push_back(t->val);
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        if(!toRight) reverse(cur.begin(),cur.end());
        toRight = !toRight;
        res.push_back(cur);
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
	return 0;
}

