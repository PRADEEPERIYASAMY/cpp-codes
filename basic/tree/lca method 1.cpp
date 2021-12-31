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

bool findPath(Node *root,vector<Node *> &p,int n){
    if(root == nullptr) return false;
    p.push_back(root);
    if(root->key == n) return true;
    if(findPath(root->left,p,n) || findPath(root->right,p,n)) return true;
    p.pop_back();
    return false;
}

Node *lca(Node *root,int n1,int n2){
    vector<Node *>p1,p2;
    if(!findPath(root,p1,n1) || !findPath(root,p2,n2)) return nullptr;
    for (int i = 0; i < p1.size()-1 && i<p2.size()-1; i++) {
        if(p1[i+1] != p2[i+1]) return p1[i];
    }
    return nullptr;
}

int main() {
    Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);
	int n1=20,n2=50;
	
	Node *ans=lca(root,n1,n2);
	cout<<"LCA: "<<ans->key;
	
	return 0;
}

