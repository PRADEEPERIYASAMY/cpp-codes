#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left, *right;
    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void inorder(node* node){
    if (node == NULL)return;
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}

int updatetree(node *root){
    if(!root) return 0;
    if(root->left == NULL && root->right == NULL) return root->data;
    int leftSum = updatetree(root->left);
    int rightSum = updatetree(root->right);
    root->data +=leftSum;
    return root->data+rightSum;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/change-a-binary-tree-so-that-every-node-stores-sum-of-all-nodes-in-left-subtree/
	struct node *root = new node(1);
    root->left     = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);
    updatetree(root);
    cout << "Inorder traversal of the modified tree is: \n";
    inorder(root);
    return 0;
}
