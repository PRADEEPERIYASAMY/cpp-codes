#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

struct Node  { 
  int key; 
  struct Node *left; 
  struct Node *right;
  Node(int k){
      key=k;
      left=right=nullptr;
  }
};

int maxValue(Node *root){
    if(root == nullptr) return INT_MIN;
    int res = root->key;
    int l = maxValue(root->left);
    int r = maxValue(root->right);
    return max(res,max(l,r));
}

int minValue(Node *root){
    if(root == nullptr) return INT_MAX;
    int res = root->key;
    int l = minValue(root->left);
    int r = minValue(root->right);
    return min(res,min(l,r));
}

int isBST(Node* root){
    if(root == nullptr) return 1;
    if(root->left!= nullptr && maxValue(root->left)>root->key) return 0;
    if(root->right != nullptr && minValue(root->right)<root->key) return 0;
    if(!isBST(root->left) || !isBST(root->right)) return 0;
    return 1;
}

int main() {
    Node *root = new Node(4);  
    root->left = new Node(2);  
    root->right = new Node(5);  
    root->left->left = new Node(1);  
    root->left->right = new Node(3);  
      
    if(isBST(root))  cout<<"Is BST";  
    else cout<<"Not a BST";  
          
    return 0; 
}

