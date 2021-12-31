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

void inorder(Node *root){
    if(root == nullptr) return;
    stack<Node *> s;
    Node *temp = root;
    while(temp != nullptr || !s.empty()){
        while(temp != nullptr){
            s.push(temp);
            temp = temp->left;
        }
        temp = s.top();
        s.pop();
        cout<<temp->key<<" ";
        temp = temp->right;
    }
}

int main() {
    Node *root=new Node(20);
	root->left=new Node(80);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);
	inorder(root);
	return 0;
}

