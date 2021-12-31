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

Node *concatenate(Node *leftList,Node *rightList){
    if(leftList==nullptr) return rightList;
    if(rightList == nullptr) return leftList;
    Node *leftLast = leftList->left;
    Node *rightLast = rightList->left;
    
    leftLast->right = rightList;
    rightList->left = leftLast;
    
    leftList->left = rightLast;
    rightLast->right = leftList;
    
    return leftList;
}

Node *bTreeToCList(Node *root){
    if(root == nullptr) return nullptr;
    Node *left = bTreeToCList(root->left);
    Node *right = bTreeToCList(root->right);
    root->left = root->right = root;
    return concatenate(concatenate(left,root),right);
}

void displayCList(Node *head){
    cout<<"Circular linked list: ";
    Node *temp = head;
    do{
        cout<<temp->key<<" ";
        temp = temp->right;
    }while(temp != head);
    cout<<"\n";
}

int main() {
    Node *root = new Node(10);
    root->left = new Node(12);
    root->right = new Node(15);
    root->left->left = new Node(25);
    root->left->right = new Node(30);
    root->right->left = new Node(36);
  
    Node *head = bTreeToCList(root);
    displayCList(head);
    return 0;
}

