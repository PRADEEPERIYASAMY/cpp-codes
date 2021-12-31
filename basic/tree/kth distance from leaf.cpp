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

int printk(Node *root,int k){
    if(root == nullptr) return 0;
    int l = printk(root->left,k);
    int r = printk(root->right,k);
    if(l == k || r == k) cout<<root->key<<" ";
    return 1+max(l,r);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
 
    int k = 2;
    printk(root, k);
	return 0;
}

