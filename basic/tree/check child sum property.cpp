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

bool isCSum(Node *root){
    if(root == nullptr) return true;
    if(root->left == nullptr && root->right == nullptr) return true;
    int sum = 0;
    if(root->left != nullptr) sum+=root->left->key;
    if(root->right != nullptr) sum+=root->right->key;
    return (sum == root->key && isCSum(root->left) && isCSum(root->right));
}

int main() {
    Node *root=new Node(20);
	root->left=new Node(8);
	root->right=new Node(12);
	root->right->left=new Node(3);
	root->right->right=new Node(9);
	
	cout<<isCSum(root);
	
	return 0;
}

