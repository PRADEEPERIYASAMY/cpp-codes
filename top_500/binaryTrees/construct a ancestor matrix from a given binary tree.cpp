#include <bits/stdc++.h>
using namespace std;
#define MAX 100

struct Node{
    int data;
    Node *left, *right;
};
 
struct Node* newnode(int key){
    struct Node* node = new Node;
    node->data = key;
    node->left = node->right = NULL;
    return node;
}

bool mat[MAX][MAX];

int ancestorMatrixRec(Node *root,vector<int> &anc){
    if(root == nullptr) return 0;
    int data = root->data;
    for (int i = 0; i < anc.size(); i++) mat[anc[i]][data] = true;
    anc.push_back(data);
    int l = ancestorMatrixRec(root->left,anc);
    int r = ancestorMatrixRec(root->right,anc);
    anc.pop_back();
    return l+r+1;
}

void ancestorMatrix(Node *root){
    vector<int> anc;
    int n = ancestorMatrixRec(root,anc);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <n; j++) cout<<mat[i][j]<<" ";
        cout<<"\n";
    }
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/construct-ancestor-matrix-from-a-given-binary-tree/
	Node *root        = newnode(5);
    root->left        = newnode(1);
    root->right       = newnode(2);
    root->left->left  = newnode(0);
    root->left->right = newnode(4);
    root->right->left = newnode(3);
    ancestorMatrix(root);
    return 0;
}
