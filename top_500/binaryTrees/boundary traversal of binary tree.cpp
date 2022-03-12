#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left, *right;
};
 
struct Node* newNode(int key){
    struct Node* node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

void printLeaves(Node *root){
    if(root == nullptr) return;
    printLeaves(root->left);
    if(!root->left && !root->right) printf("%d ",root->key);
    printLeaves(root->right);
}

void printBoundaryLeft(Node *root){
    if(root == nullptr) return;
    if(root->left){
        printf("%d ",root->key);
        printBoundaryLeft(root->left);
    }else if(root->right){
        printf("%d ",root->key);
        printBoundaryLeft(root->right);
    }
}

void printBoundaryRight(Node *root){
    if(root == nullptr) return;
    if(root->right){
        printBoundaryRight(root->right);
        printf("%d ",root->key);
    }else if(root->left){
        printBoundaryRight(root->left);
        printf("%d ",root->key);
    }
}

void printBoundary(Node *root){
    if(root == nullptr) return;
    printf("%d ",root->key);
    printBoundaryLeft(root->left);
    printLeaves(root->left);
    printLeaves(root->right);
    printBoundaryRight(root->right);
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/
	Node* root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);
    printBoundary(root);
    return 0;
}
