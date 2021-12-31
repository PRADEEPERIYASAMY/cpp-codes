#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

struct Node{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k){
        key = k;
        left = right = nullptr;
    }
};

bool IsFoldableUtil(Node *left,Node *right){
    if(left == nullptr && right == nullptr) return true;
    if(left == nullptr || right == nullptr) return false;
    return IsFoldableUtil(left->left,right->right) && IsFoldableUtil(left->right,right->left);
}

bool IsFoldable(Node *root){
    if(root == nullptr) return true;
    return IsFoldableUtil(root->left,root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
 
    if (IsFoldable(root) == true) cout << "Tree is foldable";
    else cout << "Tree is not foldable";
	
	return 0;
}

