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

void lengthUtil(Node *root,int &maximum,int &minimum,int cur =0){
    if(root == nullptr) return;
    lengthUtil(root->left,maximum,minimum,cur-1);
    minimum = min(minimum,cur);
    maximum = max(maximum,cur);
    lengthUtil(root->right,maximum,minimum,cur+1);
}

int getLength(Node *root){
    int maximum = 0,minimum = 0;
    lengthUtil(root,maximum,minimum,0);
    return (abs(minimum)+maximum)+1;
}

int main() {
     Node* root = new Node(7);
    root->left = new Node(6);
    root->right = new Node(5);
    root->left->left = new Node(4);
    root->left->right = new Node(3);
    root->right->left = new Node(2);
    root->right->right = new Node(1);
  
    cout << getLength(root) << "\n";
	return 0;
}

