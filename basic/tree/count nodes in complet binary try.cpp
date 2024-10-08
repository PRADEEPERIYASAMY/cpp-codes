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

int countNode(Node *root){
    int lh = 0,rh = 0;
    Node *cur = root;
    while(cur != nullptr){
        lh++;
        cur = cur->left;
    }
    cur = root;
    while(cur != nullptr){
        rh++;
        cur = cur->right;
    }
    if(lh == rh) return pow(2,lh)-1;
    else return 1+countNode(root->left)+countNode(root->right);
}

int main() {
    Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);
	cout<<countNode(root);
	
	return 0;
}

