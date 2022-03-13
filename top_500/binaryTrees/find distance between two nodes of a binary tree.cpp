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

int findLevel(Node *root,int k,int level){
    if(root == nullptr) return -1;
    if(root->key == k) return level;
    int left = findLevel(root->left,k,level+1);
    if(left == -1) return findLevel(root->right,k,level+1);
    return left;
}

int findDistance(Node *root,int a,int b){
    Node *lca = findLCA(root,a,b);
    int d1 = findLevel(lca,a,0);
    int d2 = findLevel(lca,b,0);
    return d1+d2;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/find-distance-between-two-nodes-of-a-binary-tree/
	Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    cout << "Dist(4, 5) = " << findDistance(root, 4, 5);
    cout << "\nDist(4, 6) = " << findDistance(root, 4, 6);
    cout << "\nDist(3, 4) = " << findDistance(root, 3, 4);
    cout << "\nDist(2, 4) = " << findDistance(root, 2, 4);
    cout << "\nDist(8, 5) = " << findDistance(root, 8, 5);
    return 0;
}
