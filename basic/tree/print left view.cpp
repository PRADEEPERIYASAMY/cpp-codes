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

void printLeft(Node *root){
    if(root == nullptr) return;
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for (int i = 0; i < n; i++) {
            Node *temp = q.front();
            q.pop();
            if(i == 0) cout<<temp->key<<" ";
            if(temp->left != nullptr) q.push(temp->left);
            if(temp->right != nullptr) q.push(temp->right);
        }
    }
}

int main() {
    Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);
	printLeft(root);
}

