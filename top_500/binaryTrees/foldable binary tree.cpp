#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
};

node* newNode(int data){
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return (Node);
}

// recursive
// bool IsFoldableUtil(node *n1,node *n2){
//     if(!n1 && !n2) return true;
//     if(!n1 || !n2) return false;
//     return IsFoldableUtil(n1->left,n2->right) && IsFoldableUtil(n1->right,n2->left);
// }

// bool IsFoldable(node *root){
//     if(root == NULL) return true;
//     return IsFoldableUtil(root->left,root->right);
// }

// iterative
bool IsFoldable(node *root){
    if(root == NULL) return true;
    queue<node*> q({root->left,root->right});
    while(!q.empty()){
        auto p = q.front();q.pop();
        auto r = q.front();q.pop();
        if(!p && !r) continue;
        if(!p || !r) return false;
        q.push(p->left),q.push(r->right),q.push(p->right),q.push(r->left);
    }
    return true;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/connect-nodes-at-same-level/
	node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(5);
    if (IsFoldable(root) == true) cout << "Tree is foldable";
    else cout << "Tree is not foldable";
    return 0;
}
