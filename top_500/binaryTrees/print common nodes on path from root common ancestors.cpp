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

Node *findLCA(Node *root,int n1,int n2){
    if(root == nullptr) return nullptr;
    if(root->key == n1 || root->key == n2) return root;
    Node *leftLca = findLCA(root->left,n1,n2);
    Node *rightLca = findLCA(root->right,n1,n2);
    if(leftLca && rightLca) return root;
    return leftLca?leftLca:rightLca;
}

bool printAncestors(Node *root,int target){
    if(root == nullptr) return false;
    if(root->key == target){
        cout<<root->key<<" ";
        return true;
    }
    if(printAncestors(root->left,target) || printAncestors(root->right,target)){
        cout<<root->key<<" ";
        return true;
    }
    return false;
}

bool findCommonNodes(Node *root,int first,int second){
    Node *lca = findLCA(root,first,second);
    if(lca == nullptr) return false;
    printAncestors(root,lca->key);
}

// only running on c++ 14
int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/print-common-nodes-path-root-common-ancestors/
	Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->right->left->left = newNode(9);
    root->right->left->right = newNode(10);
    if (findCommonNodes(root, 9, 7) == false)cout << "No Common nodes";
    return 0;
}
