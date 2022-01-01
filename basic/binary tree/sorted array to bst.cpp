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

void preOrder(Node* node){
    if (node == NULL)return;
    cout << node->key << " ";
    preOrder(node->left);
    preOrder(node->right);
}

Node* sortedArrayToBST(int arr[],int s,int e){
    if(s>e) return nullptr;
    int mid = (s+e)/2;
    Node *root = new Node(arr[mid]);
    root->left = sortedArrayToBST(arr,s,mid-1);
    root->right = sortedArrayToBST(arr,mid+1,e);
    return root;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *root = sortedArrayToBST(arr, 0, n-1);
    cout << "PreOrder Traversal of constructed BST \n";
    preOrder(root);
    return 0;
}

