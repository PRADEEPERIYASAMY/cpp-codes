#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left, *middle, *right;
};

Node* newNode(int data){
    Node* node = new Node;
    node->data = data;
    node->left = node->middle = node->right = nullptr;
    return node;
}

void push(Node** tail_ref, Node* node){
    if (*tail_ref == nullptr){
        *tail_ref = node;
        node->left = node->middle = node->right = nullptr;
        return;
    }
    (*tail_ref)->right = node;
    node->left = (*tail_ref);
    node->right = node->middle = nullptr;
    (*tail_ref) = node;
}

void printList(Node* head){
    printf("Created Double Linked list is:\n");
    while (head){
        printf("%d ", head->data);
        head = head->right;
    }
}

Node *TernaryTreeToList(Node *root,Node *&headRef){
    if(root == nullptr) return nullptr;
    static Node *tail = nullptr;
    Node *left = root->left;
    Node *middle = root->middle;
    Node *right = root->right;
    if(headRef == nullptr) headRef = root;
    push(&tail,root);
    TernaryTreeToList(left,headRef);
    TernaryTreeToList(middle,headRef);
    TernaryTreeToList(right,headRef);
}

// working in c++14 only
int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/create-doubly-linked-list-ternary-ree/
	Node* root = newNode(30);
    root->left = newNode(5);
    root->middle = newNode(11);
    root->right = newNode(63);
    root->left->left = newNode(1);
    root->left->middle = newNode(4);
    root->left->right = newNode(8);
    root->middle->left = newNode(6);
    root->middle->middle = newNode(7);
    root->middle->right = newNode(15);
    root->right->left = newNode(31);
    root->right->middle = newNode(55);
    root->right->right = newNode(65);
    Node* head = nullptr;
    TernaryTreeToList(root,head);
    printList(head);
    return 0;
}
