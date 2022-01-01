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

Node* constructTree(int pre[],int n){
    stack<Node*> s;
    Node *root = new Node(pre[0]);
    s.push(root);
    Node *temp;
    for (int i = 1; i < n; i++) {
        temp = nullptr;
        while(!s.empty() && pre[i]>s.top()->key){ // pop untill stack top is greater than pre[i]
            temp = s.top();
            s.pop();
        }
        if(temp){
            temp->right = new Node(pre[i]);
            s.push(temp->right);
        }else{
            s.top()->left = new Node(pre[i]);
            s.push(s.top()->left);
        }
    }
    return root;
}

void printInorder (Node* node){
    if (node == NULL) return;
    printInorder(node->left);
    cout<<node->key<<" ";
    printInorder(node->right);
}

int main(){
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof( pre ) / sizeof( pre[0] );
    Node *root = constructTree(pre, size);
    cout<<"Inorder traversal of the constructed tree: \n";
    printInorder(root);
    return 0;
}

