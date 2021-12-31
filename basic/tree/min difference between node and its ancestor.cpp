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

int maxDiffUtil(Node *root, int &res){
    if(root == nullptr) return INT_MAX;
    if( !root->left && !root->right) return root->key;
    
    int val = min(maxDiffUtil(root->left,res),maxDiffUtil(root->right,res));
    res = max(res,root->key - val);
    return min(val,root->key);
}

int maxDiff(Node *root){
    int res = INT_MIN;
    maxDiffUtil(root,res);
    return res;
}

int main() {
    Node* root;
    root = new Node(8);
    root->left = new Node(3);
 
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
 
    root->right = new Node(10);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
 
    printf("Maximum difference between a node and its ancestor is : %d\n", maxDiff(root));
	
	return 0;
}

