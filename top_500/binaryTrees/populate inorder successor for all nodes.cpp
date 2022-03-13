#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;
    node *next;
};

node* newnode(int data){
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    Node->next = NULL;
    return(Node);
}

void populateNext(node *p){
    static node *next = nullptr;
    if(!p) return;
    populateNext(p->right);
    p->next = next;
    next = p;
    populateNext(p->left);
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/populate-inorder-successor-for-all-nodes/
	node *root = newnode(10);
    root->left = newnode(8);
    root->right = newnode(12);
    root->left->left = newnode(3);
    populateNext(root);
    node *ptr = root->left->left;
    while(ptr){
        cout << "Next of " << ptr->data << " is "<< (ptr->next? ptr->next->data: -1)<< endl;
        ptr = ptr->next;
    }
    return 0;
}
