#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left, *right;
};

node* newnode(int data){
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return(Node);
}

bool hasPathSum(node *root,int sum){
    bool ans = 0;
    int subSum = 0 - root->data;
    if(subSum == 0 && !root->left && !root->right) return 1;
    if(root->left) ans = ans|| hasPathSum(root->left,subSum);
    if(root->right) ans = ans|| hasPathSum(root->right,subSum);
    return ans;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/root-to-leaf-path-sum-equal-to-a-given-number/
	int sum = 21;
    node *root = newnode(10);
    root->left = newnode(8);
    root->right = newnode(2);
    root->left->left = newnode(3);
    root->left->right = newnode(5);
    root->right->left = newnode(2);
     
    if(hasPathSum(root, sum)) cout << "There is a root-to-leaf path with sum " << sum;
    else cout << "There is no root-to-leaf path with sum " << sum;
    return 0;
}
