#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    struct Node *left, *right;
};

Node* newNode(int data){
    Node* temp = new Node;
    temp->val = data;
    temp->left = temp->right = NULL;
    return temp;
}

int traverse(Node *root,int &tilt){
    if(!root) return 0;
    int left = traverse(root->left,tilt);
    int right = traverse(root->right,tilt);
    tilt += abs(left - right);
    return left+right+root->val;
}

int Tilt(Node *root){
    int tilt = 0;
    traverse(root,tilt);
    return tilt;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/tilt-binary-tree/
	Node* root = NULL;
    root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(9);
    root->left->left = newNode(3);
    root->left->right = newNode(8);
    root->right->right = newNode(7);
    cout << "The Tilt of whole tree is " << Tilt(root);
    return 0;
}

