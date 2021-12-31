#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

struct Node{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k){
        key = k;
        left = right= nullptr;
    }
};

void inorder(Node *root){
    if (root != NULL){
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

void createNode(int parent[],int i,Node *created[],Node **root){
    if(created[i] != nullptr) return;
    created[i] = new Node(i);
    if(parent[i] == -1){
        *root = created[i];
        return;
    }
    if(created[parent[i]] == nullptr)createNode(parent,parent[i],created,root);
    Node *temp = created[parent[i]];
    if(temp->left == nullptr) temp->left = created[i];
    else temp->right = created[i];
}

Node *createTree(int parent[],int n){
    Node *created[n];
    for (int i = 0; i < n; i++) created[i] = nullptr;
    
    Node *root = nullptr;
    for (int i = 0; i < n; i++) createNode(parent,i,created,&root);
    
    return root;
}

int main() {
    int parent[] =  {-1, 0, 0, 1, 1, 3, 5};
    int n = sizeof parent / sizeof parent[0];
    Node *root = createTree(parent, n);
    cout << "Inorder Traversal of constructed tree\n";
    inorder(root);
    return 0;
}

