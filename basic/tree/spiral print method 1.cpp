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

void printlist(Node *root){
    Node *temp = root;
    while(temp != nullptr){
        cout<<temp->key<<" ";
        temp = temp->right;
    }
    cout<<endl;
}

void printSpiral(Node *root){
    if(root == nullptr) return;
    queue<Node *> q;
    stack<int> s;
    bool reverse = false;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for (int i = 0; i < n; i++) {
            Node *temp = q.front();
            q.pop();
            if(reverse) s.push(temp->key);
            else cout<<temp->key<<" ";
            if(temp->left != nullptr) q.push(temp->left);
            if(temp->right != nullptr) q.push(temp->right);
        }
        if(reverse){
            while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();    
            }
        }
        reverse = !reverse;
    }
}

int main() {
    Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	
	printSpiral(root);
	
	return 0;
}

