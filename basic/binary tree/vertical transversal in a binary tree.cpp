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

void vTraversal(Node *root){
    map<int,vector<int>> mp;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto temp = q.front();
        q.pop();
        Node *cur = temp.first;
        int hd = temp.second;
        mp[hd].push_back(cur->key);
        if(cur->left) q.push({cur->left,hd-1});
        if(cur->right) q.push({cur->right,hd+1});
    }
    for (auto &x : mp) {
        for (auto &i : x.second) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

int main() {
    Node *root = new Node(10);  
    root->left = new Node(20);  
    root->right = new Node(30);  
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    
    vTraversal(root);
          
    return 0; 
}

