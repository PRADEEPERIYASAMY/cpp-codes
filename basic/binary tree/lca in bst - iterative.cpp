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

Node* lca(Node *root,int n1,int n2){
    while(root != nullptr){
        int val = root->key;
        if(val >n1 && val >n2) root= root->left;
        else if(val<n1 && val<n2) root = root->right;
        else break;
    }
    return root;
}

int main() {
    Node *root = new Node(20); 
    root->left = new Node(8); 
    root->right = new Node(22); 
    root->left->left = new Node(4); 
    root->left->right = new Node(12); 
    root->left->right->left = new Node(10); 
    root->left->right->right = new Node(14); 

    int n1 = 10, n2 = 14; 
    Node *t = lca(root, n1, n2); 
    cout << "LCA of " << n1 << " and " << n2 << " is " << t->key<<endl; 

    n1 = 14, n2 = 8; 
    t = lca(root, n1, n2); 
    cout<<"LCA of " << n1 << " and " << n2 << " is " << t->key << endl; 

    n1 = 10, n2 = 22; 
    t = lca(root, n1, n2); 
    cout << "LCA of " << n1 << " and " << n2 << " is " << t->key << endl; 
    return 0; 
}

