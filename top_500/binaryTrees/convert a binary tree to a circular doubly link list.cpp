#include <bits/stdc++.h>
using namespace std;

struct Node{
    struct Node *left, *right;
    int data;
};

void displayCList(Node *head){
    cout << "Circular Linked List is :\n";
    Node *itr = head;
    do{
        cout << itr->data <<" ";
        itr = itr->right;
    } while (head!=itr);
    cout << "\n";
}
  
Node *newNode(int data){
    Node *temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node *concatenate(Node *leftList,Node *rightList){
    if(leftList == nullptr) return rightList;
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

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/convert-a-binary-tree-to-a-circular-doubly-link-list/
	Node *root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(15);
    root->left->left = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);
    Node *head = bTreeToCList(root);
    displayCList(head);
    return 0;
}
