#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
 
struct Node* newNode(int data){
    struct Node* Node = (struct Node*)malloc(sizeof(struct Node));
    Node->data = data;
    Node->left = Node->right = NULL;
    return Node;
}

void diagonalSumUtil(Node *root,int vd,map<int,int> &mp){
    if(!root) return;
    mp[vd]+=root->data;
    diagonalSumUtil(root->left,vd+1,mp);
    diagonalSumUtil(root->right,vd,mp);
}

void diagonalSum(Node *root){
    map<int,int> mp;
    diagonalSumUtil(root,0,mp);
    for (auto [first,second] : mp) cout<<second<<" ";
}

// recursion can be solved using queue also - so refer diagonal traverse for this

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/diagonal-sum-binary-tree/
	struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(9);
    root->left->right = newNode(6);
    root->right->left = newNode(4);
    root->right->right = newNode(5);
    root->right->left->right = newNode(7);
    root->right->left->left = newNode(12);
    root->left->right->left = newNode(11);
    root->left->left->right = newNode(10);
    diagonalSum(root);
    return 0;
}

