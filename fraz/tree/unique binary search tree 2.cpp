#include <iostream>
using namespace std;

vector<TreeNode*> helper(int start,int end){
    vector<TreeNode*> res;
    if(start>end){
        res.push_back(nullptr);
        return res;
    }
    for (int i = start; i <= end; i++) {
        auto left = helper(start,i-1),right = helper(i+1,end);
        for (auto &l : left) {
            for (auto &r : right) {
                TreeNode* root = new TreeNode(i);
                root->left = l;
                root->right = r;
                res.push_back(root);
            }
        }
    }
    return res;
}

vector<TreeNode*> generateTrees(int n) {
    if(n == 0) return {};
    return helper(1,n);
}

int main() {
	// leetcode
	// https://leetcode.com/problems/unique-binary-search-trees-ii/
	return 0;
}

