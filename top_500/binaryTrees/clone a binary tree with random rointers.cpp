#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    struct Node* left, *right, *random;
};

Node* newNode(int key){
    Node* temp = new Node;
    temp->key = key;
    temp->random = temp->right = temp->left = NULL;
    return (temp);
}

void printInorder(Node* node){
    if (node == NULL) return;
    printInorder(node->left);
    cout << "[" << node->key << " ";
    if (node->random == NULL) cout << "NULL], ";
    else cout << node->random->key << "], ";
    printInorder(node->right);
}

// using hashing
// Node *copyLeftRight(Node *root,unordered_map<Node*,Node*> &mp){
//     if(root == nullptr) return nullptr;
//     Node * clone = newNode(root->key);
//     mp[root] = clone;
//     clone->left = copyLeftRight(root->left,mp);
//     clone->right = copyLeftRight(root->right,mp);
//     return clone;
// }

// void copyRandom(Node *root,Node *clone,unordered_map<Node*,Node*> mp){
//     if(clone == nullptr) return;
//     clone->random = mp[root->random];
//     copyRandom(root->left,clone->left,mp);
//     copyRandom(root->right,clone->right,mp);
// }

// Node *cloneTree(Node *root){
//     if(root == nullptr) return nullptr;
//     unordered_map<Node*,Node*> mp;
//     Node* newTree = copyLeftRight(root,mp);
//     copyRandom(root,newTree,mp);
//     return newTree;
// }

// using temporary change
Node *copyLeftRight(Node *root){
    if(root == nullptr) return nullptr;
    Node *left = root->left;
    root->left = newNode(root->key);
    root->left->left = left;
    if(left) left->left = copyLeftRight(left);
    root->left->right = copyLeftRight(root->right);
    return root->left;
}

void copyRandom(Node *root,Node *clone){
    if(root == nullptr) return;
    if(root->random != nullptr) clone->random = root->random->left;
    else clone->random = nullptr;
    if(root->left != nullptr && clone->left != nullptr) copyRandom(root->left->left,clone->left->left);
    copyRandom(root->right,clone->right);
}

void restoreTreeLeftNode(Node *root,Node *clone){
    if(root == nullptr) return;
    if(clone->left != nullptr){
        Node *cloneLeft = clone->left->left;
        root->left = root->left->left;
        clone->left = cloneLeft;
    }else root->left = nullptr;
    
    restoreTreeLeftNode(root->left,clone->left);
    restoreTreeLeftNode(root->right,clone->right);
}

Node *cloneTree(Node *root){
    if(root == nullptr) return nullptr;
    Node *cloneNode = copyLeftRight(root);
    copyRandom(root,cloneNode);
    restoreTreeLeftNode(root,cloneNode);
    return cloneNode;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/clone-binary-tree-random-pointers/
	Node *tree = newNode(1);
    tree->left = newNode(2);
    tree->right = newNode(3);
    tree->left->left = newNode(4);
    tree->left->right = newNode(5);
    tree->random = tree->left->right;
    tree->left->left->random = tree;
    tree->left->right->random = tree->right;
    cout << "Inorder traversal of original binary tree is: \n";
    printInorder(tree);
    Node *clone = cloneTree(tree);
    cout << "\n\nInorder traversal of cloned binary tree is: \n";
    printInorder(clone);
    return 0;
}
