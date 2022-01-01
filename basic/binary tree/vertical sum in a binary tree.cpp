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

void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

void vSumR(Node *root,int hd,map<int,int> &mp){
    if(root == nullptr) return;
    vSumR(root->left,hd-1,mp);
    mp[hd]+=root->key;
    vSumR(root->right,hd+2,mp);
}

void vSum(Node *root){
    map<int,int> mp;
    vSumR(root,0,mp);
    for(auto sum: mp) cout<<sum.second<<" ";
}

int main() {
    Node *root = new Node(10);  
    root->left = new Node(20);  
    root->right = new Node(50);  
    root->left->left = new Node(30);
    root->left->right = new Node(40);
    
    vSum(root);
          
    return 0;     
}

