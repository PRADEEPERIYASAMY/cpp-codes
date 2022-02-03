#include <iostream>
using namespace std;

// Node* connect(Node* root) {
//     if(!root) return root;
//     queue<Node*> q({root});
//     while(!q.empty()){
//         for (int i = q.size()-1; i >= 0; i--) {
//             Node *t = q.front();q.pop();
//             t->next = i == 0? nullptr:q.front();
//             if(t->left) q.push(t->left);
//             if(t->right) q.push(t->right);
//         }
//     }
//     return root;
// }

Node* connect(Node* root) {
    if(!root) return root;
    if(root->left) root->left->next = root->right;
    if(root->right) root->right->next = root->next?root->next->left:nullptr;
    connect(root->left);
    connect(root->right);
    return root;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
	return 0;
}

