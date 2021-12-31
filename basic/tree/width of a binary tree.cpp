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

int maxWidth(Node *root){
    if(root == nullptr) return 0;
    queue<Node *> q;
    q.push(root);
    int res = 0;
    while(!q.empty()){
        int n = q.size();
        res = max(res,n);
        for (int i = 0; i < n; i++) {
            Node *temp = q.front();
            q.pop();
            if(temp->left != nullptr) q.push(temp->left);
            if(temp->right != nullptr) q.push(temp->right);
        }
    }
    return res;
}

int main() {
    Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->right->left=new Node(60);
	
	cout<<maxWidth(root);
	
	return 0;
}

