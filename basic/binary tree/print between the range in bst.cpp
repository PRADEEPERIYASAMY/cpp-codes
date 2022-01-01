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

void Print(Node *root,int k1,int k2){
    if( root == nullptr) return;
    int val = root->key;
    if(k1<val) Print(root->left,k1,k2);
    if(k1<=val && k2>=val ) cout<<val<<" ";
    Print(root->right,k1,k2);
}

int main() {
    Node *root;
    int k1 = 10, k2 = 25; 
    root = new Node(20); 
    root->left = new Node(8); 
    root->right = new Node(22); 
    root->left->left = new Node(4); 
    root->left->right = new Node(12); 
    
    Print(root, k1, k2); 
    return 0; 
}

