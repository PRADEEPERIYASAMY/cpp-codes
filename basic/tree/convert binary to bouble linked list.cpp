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

void printlist(Node *root){
    Node *temp = root;
    while(temp != nullptr){
        cout<<temp->key<<" ";
        temp = temp->right;
    }
    cout<<endl;
}

Node *BTToDLL(Node *root){
    if(root == nullptr) return root;
    static Node *prev = nullptr;
    Node *head = BTToDLL(root->left);
    if(prev == nullptr) head = root;
    else{
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    BTToDLL(root->right);
    return head;
}

int main() {
    Node *root=new Node(10);
	root->left=new Node(5);
	root->right=new Node(20);
	root->right->left=new Node(30);
	root->right->right=new Node(35);
	
	Node *head=BTToDLL(root);
	printlist(head);
	
	return 0;
}

