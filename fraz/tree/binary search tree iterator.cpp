#include <iostream>
using namespace std;

class BSTIterator {
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        if(root){
            TreeNode *cur = root;
            find_left(cur);
        }
    }
    
    int next() {
        TreeNode *t = st.top();st.pop();
        int next_smallest = t->val;
        find_left(t->right);
        return next_smallest;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    
    void find_left(TreeNode *node){
        while(node){
            st.push(node);
            node = node->left;
        }
    }
};

int main() {
	// leetcode
	// https://leetcode.com/problems/binary-search-tree-iterator/
	return 0;
}

