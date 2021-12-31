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

int countSubtreesWithSumXUtil(Node *root,int x){
    static int count = 0;
    static Node* ptr = root;
    int l = 0,r = 0;
    if(root==nullptr) return 0;
    l+=countSubtreesWithSumXUtil(root->left,x);
    r+=countSubtreesWithSumXUtil(root->right,x);
    if(l+r+root->key == x) count++;
    if(ptr != root) return l+r+root->key;
    return count;
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(-10);
    root->right = new Node(3);
    root->left->left = new Node(9);
    root->left->right = new Node(8);
    root->right->left = new Node(-4);
    root->right->right = new Node(7);
 
    int x = 7;
 
    cout << "Count = "<< countSubtreesWithSumXUtil(root, x);
	return 0;
}

