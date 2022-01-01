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

Node* root;

void  preorderTraversal(Node* root){
    if (root == NULL)return;
    cout<<(root->key) << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

Node* LevelOrder(Node* root,int data){
    if(root == nullptr){
        root = new Node(data);
        return root;
    }
    if(data<= root->key) root->left = LevelOrder(root->left,data);
    else root->right = LevelOrder(root->right,data);
    return root;
}

Node* constructBst(int arr[],int n){
    if(n == 0) return nullptr;
    root = nullptr;
    for (int i = 0; i < n; i++) root = LevelOrder(root,arr[i]);
    return root;
}

int main() {
    int arr[] = { 7, 4, 12, 3, 6, 8, 1, 5, 10 };
    int n = sizeof(arr)/sizeof(arr[0]);
    root = constructBst(arr, n);
    preorderTraversal(root);
    return 0;
}

