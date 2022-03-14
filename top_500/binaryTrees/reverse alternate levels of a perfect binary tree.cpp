#include <bits/stdc++.h>
using namespace std;

struct Node{
    char key;
    Node *left, *right;
};

Node *newNode(int key){
    Node *temp = new Node;
    temp->left = temp->right = NULL;
    temp->key = key;
    return temp;
}

void printInorder(struct Node *root){
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->key << " ";
    printInorder(root->right);
}

void preorder(Node *root1,Node *root2,int lvl){
    if(root1 == NULL || root2 == NULL) return;
    if(lvl%2 == 0) swap(root1->key,root2->key);
    preorder(root1->left,root2->right,lvl+1);
    preorder(root1->right,root2->left,lvl+1);
}

void reverseAlternate(Node *root){
    preorder(root->left,root->right,0);
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/reverse-alternate-levels-binary-tree/
	struct Node *root = newNode('a');
    root->left = newNode('b');
    root->right = newNode('c');
    root->left->left = newNode('d');
    root->left->right = newNode('e');
    root->right->left = newNode('f');
    root->right->right = newNode('g');
    root->left->left->left = newNode('h');
    root->left->left->right = newNode('i');
    root->left->right->left = newNode('j');
    root->left->right->right = newNode('k');
    root->right->left->left = newNode('l');
    root->right->left->right = newNode('m');
    root->right->right->left = newNode('n');
    root->right->right->right = newNode('o');
    cout << "Inorder Traversal of given tree\n";
    printInorder(root);
    reverseAlternate(root);
    cout << "\n\nInorder Traversal of modified tree\n";
    printInorder(root);
    return 0;
}
