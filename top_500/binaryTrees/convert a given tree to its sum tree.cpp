#include <bits/stdc++.h>
using namespace std;

class node{
    public:
int data;
node *left;
node *right;
};

void printInorder(node* Node){
    if (Node == NULL) return;
    printInorder(Node->left);
    cout<<" "<<Node->data;
    printInorder(Node->right);
}

node* newNode(int data){
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int toSumTree(node *root){
    if(root == NULL) return 0;
    int oldVal = root->data;
    root->data = toSumTree(root->left)+toSumTree(root->right);
    return root->data + oldVal;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/convert-a-given-tree-to-sum-tree/
	node *root = NULL;
    int x;
    root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(6);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
    root->right->left = newNode(7);
    root->right->right = newNode(5);
    toSumTree(root);
    cout<<"Inorder Traversal of the resultant tree is: \n";
    printInorder(root);
    return 0;
    return 0;
}
