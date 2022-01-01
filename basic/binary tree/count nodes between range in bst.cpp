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

int getCount(Node *root,int low,int high){
    if(root == nullptr) return 0;
    if(root->key == high && root->key == low) return 1;
    
    if(root->key <= high && root->key >= low) return 1+getCount(root->left,low,high)+getCount(root->right,low,high);
    
    if(root->key > high) return getCount(root->left,low,high);
    return getCount(root->right,low,high);
}

int main(){
    Node *root        = new Node(10);
    root->left        = new Node(5);
    root->right       = new Node(50);
    root->left->left  = new Node(1);
    root->right->left = new Node(40);
    root->right->right = new Node(100);

    int l = 5;
    int h = 45;
    cout << "Count of nodes between [" << l << ", " << h << "] is " << getCount(root, l, h);
    return 0;
}

