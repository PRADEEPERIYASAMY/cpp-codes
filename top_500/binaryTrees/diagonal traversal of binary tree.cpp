#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* newNode(int data){
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// using hash
// void diagonalPrintUtil(Node *root,int d,map<int,vector<int>> &mp){
//     if(!root) return;
//     mp[d].push_back(root->data);
//     diagonalPrintUtil(root->left,d+1,mp);
//     diagonalPrintUtil(root->right,d,mp);
// }

// void diagonalPrint(Node *root){
//     map<int,vector<int>> mp;
//     diagonalPrintUtil(root,0,mp);
//     cout<<"Diagonal Traversal of binary tree : \n";
//     for (auto [first,second] : mp) {
//         for (auto &i : second) cout<<i<<" ";
//         cout<<"\n";
//     }
// }

// using queue 
void diagonalPrint(Node *root){
    if(!root) return;
    vector<int> res;
    queue<Node*> q;
    while(root){
        res.push_back(root->data);
        if(root->left) q.push(root->left);
        if(root->right) root = root->right;
        else{
            if(!q.empty()){
                root = q.front();
                q.pop();
            }else root = nullptr;
        }
    }
    for (auto &i : res) cout<<i<<" ";
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/diagonal-traversal-of-binary-tree/
	 Node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
    diagonalPrint(root);
    return 0;
}
