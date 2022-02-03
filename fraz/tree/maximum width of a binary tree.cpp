#include <iostream>
using namespace std;

//dfs
// int dfs(TreeNode *root,int id,int d,vector<int> &lefts){
//     if(!root) return 0;
//     if(d>= lefts.size()) lefts.push_back(id);
//     return max({id+1- lefts[d],dfs(root->left,id*2,d+1,lefts),dfs(root->right,id*2+1,d+1,lefts)});
// }

// int widthOfBinaryTree(TreeNode* root) {
//     vector<int> lefts;
//     return dfs(root,1,0,lefts);
// }

//bfs 
int widthOfBinaryTree(TreeNode* root) {
    if(!root) return 0;
    unsigned int res = 1;
    queue<pair<TreeNode*,unsigned int>> q({{root,1}});
    while(!q.empty()){
        unsigned l = q.front().second,r = l;
        unsigned n = q.size();
        for (int i = 0; i < n; i++) {
            TreeNode *t = q.front().first;
            r = q.front().second;
            q.pop();
            if(t->left) q.push({t->left,r*2});
            if(t->right) q.push({t->right,r*2+1});
        }
        res = max(res,r-l+1);
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/maximum-width-of-binary-tree/discuss/106645/C%2B%2BJava-*-BFSDFS3liner-Clean-Code-With-Explanation
	return 0;
}

