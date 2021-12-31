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

int getMax(Node *root){
    if(root == nullptr) return INT_MIN;
    return max(root->key,max(getMax(root->left),getMax(root->right)));
}

int main() {
    Node *root=new Node(20);
	root->left=new Node(80);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);
	cout<<getMax(root);
	return 0;
}

