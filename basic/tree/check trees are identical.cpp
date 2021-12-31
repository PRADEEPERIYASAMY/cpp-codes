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

bool identicalTrees(Node *root1,Node *root2){
    if(root1 != nullptr && root2 != nullptr) return true;
    if(root1 != nullptr || root2 != nullptr) return false;
    return (root1->key == root1->key) && identicalTrees(root1->left,root2->left) && identicalTrees(root1->right,root2->right); 
}

int main() {
    Node *root1 = new Node(1); 
    Node *root2 = new Node(1); 
    root1->left = new Node(2); 
    root1->right = new Node(3); 
    root1->left->left = new Node(4); 
    root1->left->right = new Node(5); 

    root2->left = new Node(2); 
    root2->right = new Node(3); 
    root2->left->left = new Node(4); 
    root2->left->right = new Node(5); 

    if(identicalTrees(root1, root2)) cout << "Both tree are identical."; 
    else cout << "Trees are not identical."; 
	return 0;
}

