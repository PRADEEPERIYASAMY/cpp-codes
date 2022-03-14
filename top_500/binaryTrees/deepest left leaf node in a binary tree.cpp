#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    struct Node *left, *right;
};
 
Node *newNode(int data){
    Node *temp = new Node;
    temp->val = data;
    temp->left = temp->right =  NULL;
    return temp;
}

void deepestLeftLeafUtil(Node *root,int lvl,int &maxlevel,bool isleft,Node *&result){
    if(root == NULL) return;
    if(isleft && !root->left && !root->right && lvl >maxlevel){
        result = root;
        maxlevel = lvl;
        return;
    }
    deepestLeftLeafUtil(root->left,lvl+1,maxlevel,true,result);
    deepestLeftLeafUtil(root->right,lvl+1,maxlevel,false,result);
}

Node *deepestLeftLeaf(Node *root){
    int maxlevel = 0;
    Node *result = NULL;
    deepestLeftLeafUtil(root,0,maxlevel,false,result);
    return result;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/deepest-left-leaf-node-in-a-binary-tree/
	Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->right = newNode(8);
    root->right->left->right->left = newNode(9);
    root->right->right->right->right = newNode(10);
 
    Node *result = deepestLeftLeaf(root);
    if (result) cout << "The deepest left child is " << result->val;
    else cout << "There is no left leaf in the given tree";
    return 0;
}
