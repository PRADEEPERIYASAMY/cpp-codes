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

void minDiffUtil(Node *root,int k,int &min_Diff,int &min_DiffKey){
    if(root == nullptr) return;
    if(root->key == k){
        min_DiffKey = root->key;
        return;
    }
    if(min_Diff > abs(root->key-k)){
        min_Diff = abs(root->key-k);
        min_DiffKey = root->key;
    }
    if(k<root->key) minDiffUtil(root->left,k,min_Diff,min_DiffKey);
    else minDiffUtil(root->right,k,min_Diff,min_DiffKey);
}

int minDiff(Node *root,int k){
    int min_Diff = INT_MAX,min_DiffKey = -1;
    minDiffUtil(root,k,min_Diff,min_DiffKey);
    return min_DiffKey;
}

int main() {
    Node *root = new Node(9);
    root->left = new Node(4);
    root->right = new Node(17);
    root->left->left = new Node(3);
    root->left->right = new Node(6);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(7);
    root->right->right = new Node(22);
    root->right->right->left = new Node(20);
    int k = 18;
    cout << minDiff(root, k);
    return 0; 
}

