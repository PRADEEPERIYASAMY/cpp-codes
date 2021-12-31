#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *nextRight;
    Node(int k){
        data = k;
        left = right= nextRight = nullptr;
    }
};

void connect(Node *root){
    queue<Node *> q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        if(temp != nullptr){
            temp->nextRight = q.front();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }else if(!q.empty()){
            q.push(nullptr);
        }
    }
}

int main() {
    struct Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->right->right = new Node(90);

    // Populates nextRight pointer in all nodes
    connect(root);

    // Let us check the values of nextRight pointers
    printf("Following are populated nextRight pointers in \n"
    "the tree (-1 is printed if there is no nextRight) \n");
    printf("nextRight of %d is %d \n", root->data,
    root->nextRight ? root->nextRight->data : -1);
    printf("nextRight of %d is %d \n", root->left->data,
    root->left->nextRight ? root->left->nextRight->data : -1);
    printf("nextRight of %d is %d \n", root->right->data,
    root->right->nextRight ? root->right->nextRight->data : -1);
    printf("nextRight of %d is %d \n", root->left->left->data,
    root->left->left->nextRight ? root->left->left->nextRight->data : -1);
    printf("nextRight of %d is %d \n", root->right->right->data,
    root->right->right->nextRight ? root->right->right->nextRight->data : -1);
    return 0;
}

