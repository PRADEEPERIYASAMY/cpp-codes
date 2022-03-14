#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
};
 
Node* newNode(int data){
    Node* node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void print(Node *root){
    if (root != NULL){
        print(root->left);
        cout<<root->data<<" ";
        print(root->right);
    }
}

void printList(Node *head){
    while (head){
        cout<<head->data<<" ";
        head = head->right;
    }
}

Node *extractLeafList(Node *root,Node *&headRef){
    if(root == NULL) return NULL;
    if(!root->left && !root->right){
        root->right = headRef;
        if(headRef) headRef->left = root;
        headRef = root;
        return NULL;
    }
    root->right = extractLeafList(root->right,headRef);
    root->left = extractLeafList(root->left,headRef);
    return root;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/connect-leaves-doubly-linked-list/
	Node *head = NULL;
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    root->left->left->left = newNode(7);
    root->left->left->right = newNode(8);
    root->right->right->left = newNode(9);
    root->right->right->right = newNode(10);
    cout << "Inorder Traversal of given Tree is:\n";
    print(root);
    root = extractLeafList(root, head);
    cout << "\nExtracted Double Linked list is:\n";
    printList(head);
    cout << "\nInorder traversal of modified tree is:\n";
    print(root);
    return 0;
}
