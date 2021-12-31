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

int maxPathSumUtil(Node *root,int &res){
    if(root == nullptr) return 0;
    if(!root->left && !root->right) return root->key;
    int ls = maxPathSumUtil(root->left,res);
    int rs = maxPathSumUtil(root->right,res);
    
    if(root->left && root->right){
        res = max(res,ls+rs+root->key);
        return max(ls,rs)+root->key;
    }
    
    if(!root->left) return rs+root->key;
    if(!root->right) return ls+root->key;
}

int maxPathSum(Node *root){
    int res = INT_MIN;
    int val = maxPathSumUtil(root,res);
    if(res == INT_MIN) return val;
    return res;
}

int main() {
    struct Node *root = new Node(-15);
    root->left = new Node(5);
    root->right = new Node(6);
    root->left->left = new Node(-8);
    root->left->right = new Node(1);
    root->left->left->left = new Node(2);
    root->left->left->right = new Node(6);
    root->right->left = new Node(3);
    root->right->right = new Node(9);
    root->right->right->right= new Node(0);
    root->right->right->right->left= new Node(4);
    root->right->right->right->right= new Node(-1);
    root->right->right->right->right->left= new Node(10);
    cout << "Max pathSum of the given binary tree is "<< maxPathSum(root);
	
	return 0;
}

