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

void printLevel(Node *root){
    if(root == nullptr) return;
    queue<Node *> q;
    q.push(root);
    q.push(nullptr);
    while(q.size()>1){
        Node *temp = q.front();
        q.pop();
        if(temp == nullptr){
            cout<<"\n";
            q.push(nullptr);
            continue;
        }
        cout<<temp->key<<" ";
        if(temp->left != nullptr) q.push(temp->left);
        if(temp->right != nullptr) q.push(temp->right);
    }
}

int main() {
    Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->right->left=new Node(60);
	root->right->right=new Node(70);
	printLevel(root);
	return 0;
}

