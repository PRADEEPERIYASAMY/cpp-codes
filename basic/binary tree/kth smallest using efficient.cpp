#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

struct Node  { 
  int key; 
  struct Node *left; 
  struct Node *right;
  int lCount;
  Node(int k){
      key=k;
      left=right=nullptr;
      lCount = 0;
  }
};

Node* insert(Node *root,int x){
    if(root == nullptr) return new Node(x);
    if(x<root->key){
        root->left = insert(root->left,x);
        root->lCount++;
    }else if(x>root->key) root->right = insert(root->right,x);
    return root;
}

Node* kthSmallest(Node *root,int k){
    if(root == nullptr) return nullptr;
    int count = root->lCount+1;
    if(k == count) return root;
    if(count>k) return kthSmallest(root->left,k);
    return kthSmallest(root->right,k- count);
}

int main() {
    Node* root = nullptr;
    int keys[] = { 20, 8, 22, 4, 12, 10, 14 };
 
    for (int x : keys) root = insert(root, x);
 
    int k = 4;
    Node* res = kthSmallest(root, k);
    if (res == nullptr) cout << "There are less than k nodes in the BST";
    else cout << "K-th Smallest Element is " << res->key;
	return 0;
}

