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

void treeToList(Node *root,vector<int> &list){
    if(root == nullptr) return;
    treeToList(root->left,list);
    list.push_back(root->key);
    treeToList(root->right,list);
}

bool isPairPresent(Node *root,int target){
    vector<int> a2;
    treeToList(root,a2);
    int s =0,e = a2.size()-1;
    while(s<e){
        if(a2[s]+a2[e] == target){
            cout<<"found"<<a2[s]<<" "<<a2[e];
            return true;
        }
        if(a2[s]+a2[e]>target) e--;
        if(a2[s]+a2[e]<target) s++;
    }
    return false;
}

int main() {
    Node *root = new Node(10);  
    root->left = new Node(8);  
    root->right = new Node(20);  
    root->left->left = new Node(4);
    root->left->right = new Node(9);
    root->right->left = new Node(11);
    root->right->right = new Node(30);  
    root->right->right->left = new Node(25);
        
    int sum=33;

    isPairPresent(root,sum);
    return 0; 
}

