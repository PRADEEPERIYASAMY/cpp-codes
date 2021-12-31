#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

struct Node{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k){
        key = k;
        left = right = nullptr;
    }
};

void preorder(Node *root){
    if(root == nullptr) return;
    stack<Node *> s;
    s.push(root);
    while(!s.empty()){
        Node* temp = s.top();
        s.pop();
        cout<<temp->key<<" ";
        if(temp->right != nullptr) s.push(temp->right);  // for preorder
        if(temp->left != nullptr) s.push(temp->left);   // need to swap these two lines for postorder
    }
}

int main() {
    Node *root=new Node(20);
	root->left=new Node(80);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);
	preorder(root);
	return 0;
}

