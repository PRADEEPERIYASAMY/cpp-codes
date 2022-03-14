#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int item){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

// void leftViewUtil(Node *root,int level,int &maxLevel){
//     if(!root) return;
//     if(maxLevel<level){
//         cout<<root->data<<" ";
//         maxLevel = level;
//     }
//     leftViewUtil(root->left,level+1,maxLevel);
//     leftViewUtil(root->right,level+1,maxLevel);
// }

// void leftView(Node *root){
//     int maxLevel = 0;
//     leftViewUtil(root,1,maxLevel);
// }

// using queue 
void leftView(Node *root){
    if(!root) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for (int i = 1; i <= n; i++) {
            Node *temp = q.front();q.pop();
            if(i == 1) cout<<temp->data<<" ";
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
        }
    }
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/print-left-view-binary-tree/
	Node* root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(8);
    root->right->right = newNode(15);
    root->right->left = newNode(12);
    root->right->right->left = newNode(14);
    leftView(root);
    return 0;
}
