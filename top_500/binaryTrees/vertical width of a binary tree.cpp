#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

Node* newNode(int data){
    Node* curr = new Node;
    curr->data = data;
    curr->left = curr->right = NULL;
    return curr;
}

void lengthUtil(Node *root,int &maximum,int &minimum,int cur = 0){
    if(root == NULL) return;
    lengthUtil(root->left,maximum,minimum,cur-1);
    minimum = min(minimum,cur);
    maximum = max(maximum,cur);
    return lengthUtil(root->right,maximum,minimum,cur+1);
}

int getLength(Node *root){
    int maximum = 0,minimum = 0;
    lengthUtil(root,maximum,minimum,0);
    return abs(minimum)+maximum+1;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/width-binary-tree-set-1/
	Node* root = newNode(7);
    root->left = newNode(6);
    root->right = newNode(5);
    root->left->left = newNode(4);
    root->left->right = newNode(3);
    root->right->left = newNode(2);
    root->right->right = newNode(1);
    cout << getLength(root) << "\n";
    return 0;
}

