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

int minValue(Node *root){
    while(root->left != nullptr) root = root->left;
    return root->key;;
}

int main() {
    Node *root = new Node(4); 
    root->left = new Node(2); 
    root->right = new Node(5); 
    root->left->left = new Node(1); 
    root->left->right = new Node(3); 
    
    cout<<minValue(root);
          
    return 0; 
}

