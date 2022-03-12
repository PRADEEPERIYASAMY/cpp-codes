#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* newNode(int data){
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void postOrderIterative(Node *root){
    if(root == nullptr) return;
    stack<Node*> s1,s2;
    s1.push(root);
    Node *temp;
    while(!s1.empty()){
        temp = s1.top();s1.pop();
        s2.push(temp);
        if(temp->left) s1.push(temp->left);
        if(temp->right) s1.push(temp->right);
    }
    while(!s2.empty()){
        temp = s2.top();s2.pop();
        cout<<temp->data<<" ";
    }
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/iterative-postorder-traversal/
	 Node* root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    postOrderIterative(root);
    return 0;
}
