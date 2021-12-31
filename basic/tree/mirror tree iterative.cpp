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

void mirror(Node *root){
    if(root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        swap(temp->left,temp->right);
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}

void inOrder(struct Node* node) 
{
    if (node == nullptr) return;
    inOrder(node->left);
    cout << node->key << " ";
    inOrder(node->right);
} 

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5); 

    cout << "Inorder traversal of the constructed"<< " tree is" << endl;
    inOrder(root);
    mirror(root); 
    cout << "\nInorder traversal of the mirror tree"<< " is \n"; 
    inOrder(root);
    return 0; 
}

