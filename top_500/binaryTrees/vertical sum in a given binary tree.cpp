#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

Node* newNode(int data){
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void verticalSumUtil(Node *node,int hd,map<int,int> &mp){
    if(node == NULL) return;
    verticalSumUtil(node->left,hd-1,mp);
    mp[hd]+=node->data;
    verticalSumUtil(node->right,hd+1,mp);
}

void verticalSum(Node *root){
    map<int,int> mp;
    verticalSumUtil(root,0,mp);
    for (auto [first,second] : mp) cout<<first<<" "<<second<<"\n";
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/vertical-sum-in-a-given-binary-tree/
	Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    cout << "Following are the values of vertical sums with the positions of the columns with respect to root\n";
    verticalSum(root);
    return 0;
}
