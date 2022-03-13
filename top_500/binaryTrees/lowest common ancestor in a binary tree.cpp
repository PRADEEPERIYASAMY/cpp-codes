#include <bits/stdc++.h>
using namespace std;
#define N 12

struct Node{
    int key;
    struct Node *left, *right;
};

Node * newNode(int k){
    Node *temp = new Node;
    temp->key = k;
    temp->left = temp->right = NULL;
    return temp;
}

// method 1 using path method
// bool findpath(Node *root,vector<int> &path,int k){
//     if(root == nullptr) return false;
//     path.push_back(root->key);
//     if(root->key == k) return true;
//     if((root->left && findpath(root->left,path,k)) || (root->right && findpath(root->right,path,k))) return true;
//     path.pop_back();
//     return false;
// }

// int findLCA(Node *root,int n1,int n2){
//     vector<int> path1,path2;
//     if(!findpath(root,path1,n1) || !findpath(root,path2,n2)) return -1;
//     int i;
//     for (i = 0; i < min(path1.size(),path2.size()); i++) {
//         if(path1[i] != path2[i]) break;
//     }
//     return path1[i-1];
// }

// single traversal
Node *findLCA(Node *root,int n1,int n2){
    if(root == nullptr) return nullptr;
    if(root->key == n1 || root->key == n2) return root;
    Node *leftLca = findLCA(root->left,n1,n2);
    Node *rightLca = findLCA(root->right,n1,n2);
    if(leftLca && rightLca) return root;
    return leftLca?leftLca:rightLca;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/
	 Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    // cout << "LCA(4, 5) = " << findLCA(root, 4, 5);
    // cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6);
    // cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4);
    // cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4);
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->key;
    cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6)->key;
    cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4)->key;
    cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4)->key;
    return 0;
}
