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

void inorder(Node *root,vector<int> &v){
    if(root == nullptr) return;
    inorder(root->left,v);
    v.push_back(root->key);
    inorder(root->right,v);
}

vector<int> findCommon(Node *root1,Node *root2){
    vector<int> v1,v2,v3;
    inorder(root1,v1);
    inorder(root2,v2);
    int i=0,j=0;
    while(i<v1.size() && j<v2.size()){
        if(v1[i] == v2[j]){
            v3.push_back(v1[i]);
            i++;j++;
        }else if(v1[i]>v2[j]) j++;
        else i++;
    }
    return v3;
}

int main() {
    Node *root1 = new Node(10); 
    root1->left = new Node(2); 
    root1->right = new Node(11); 
    root1->left->left = new Node(1); 
    root1->left->right = new Node(3); 
    
    Node *root2 = new Node(2);
    root2->left = new Node(1);
    root2->right = new Node(3);
    
    auto x = findCommon(root1,root2);
    for (auto &i : x) cout<<i<<" ";
          
    return 0; 
}

