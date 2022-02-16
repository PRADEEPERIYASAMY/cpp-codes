#include <iostream>
using namespace std;

// 0: has a leaf child uncoved
// 1: a leaf parentwith camera
// 2: covered without camera
int helper(TreeNode *root,int &res){
    if(!root) return 2;
    int left = helper(root->left,res),right = helper(root->right,res);
    if(left == 0|| right == 0) {
        res++;
        return 1;
    }
    return (left == 1 || right == 1) ?2:0;
}

int minCameraCover(TreeNode* root) {
    int res = 0;
    if(helper(root,res)<1) res++;
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/binary-tree-cameras/
	return 0;
}

