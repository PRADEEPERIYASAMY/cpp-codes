#include <iostream>
using namespace std;

TreeNode* helper(vector<int> &pre,int preL,int preR,vector<int> &post,int postL,int postR,unordered_map<int,int> &mp){
    if(preL>preR || postL>postR) return nullptr;
    TreeNode *node = new TreeNode(pre[preL]);
    if(preL == preR) return node;
    int idx = mp[pre[preL+1]];
    node->left = helper(pre,preL+1,preL+1+(idx-postL),post,postL,idx,mp);
    node->right = helper(pre,preL+1+(idx-postL)+1,preR,post,idx+1,postR-1,mp);
    return node;
}

TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    unordered_map<int,int> mp;
    for (int i = 0; i < post.size(); i++) mp[post[i]] = i;
    return helper(pre,0,pre.size()-1,post,0,post.size()-1,mp);
}

int main() {
	// leetcode
	// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
	return 0;
}

