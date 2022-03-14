#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left, *right;
};

struct Node* newNode(int data){
    struct Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return (newNode);
}

int findmaxUtil(Node *root,int &res){
    if(root == NULL) return 0;
    int l = findmaxUtil(root->left,res);
    int r = findmaxUtil(root->right,res);
    
    int maxSingle = max(max(l,r)+root->data,root->data);
    int maxTop = max(maxSingle,l+r+root->data);
    res = max(res,maxTop);
    return maxSingle;
}

int findMaxSum(Node *root){
    int res = INT_MIN;
    findmaxUtil(root,res);
    return res;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/find-maximum-path-sum-in-a-binary-tree/
	struct Node *root = newNode(10);
    root->left        = newNode(2);
    root->right       = newNode(10);
    root->left->left  = newNode(20);
    root->left->right = newNode(1);
    root->right->right = newNode(-25);
    root->right->right->left   = newNode(3);
    root->right->right->right  = newNode(4);
    cout << "Max path sum is " << findMaxSum(root);
    return 0;
}

