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

bool areIdentical(Node * root1, Node *root2) { 
    if (root1 == NULL && root2 == NULL) return true; 
    if (root1 == NULL || root2 == NULL) return false; 
    return (root1->key == root2->key && areIdentical(root1->left, root2->left) && areIdentical(root1->right, root2->right) ); 
} 

bool isSubtree(Node *T,Node *S){
    if(S == nullptr) return true;
    if(T == nullptr) return false;
    if(areIdentical(T,S)) return true;
    return isSubtree(T->left,S) || isSubtree(T->right,S);
}

int main() {
    Node *T = new Node(26); 
    T->right         = new Node(3); 
    T->right->right = new Node(3); 
    T->left         = new Node(10); 
    T->left->left     = new Node(4); 
    T->left->left->right = new Node(30); 
    T->left->right     = new Node(6); 

    Node *S = new Node(10); 
    S->right     = new Node(6); 
    S->left     = new Node(4); 
    S->left->right = new Node(30); 

    if (isSubtree(T, S)) cout << "Tree 2 is subtree of Tree 1"; 
    else cout << "Tree 2 is not a subtree of Tree 1"; 
    return 0;
}

