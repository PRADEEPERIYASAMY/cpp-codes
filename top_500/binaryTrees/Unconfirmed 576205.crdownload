#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data){
    struct Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

int maxWidth(Node *root){
    if(!root) return 0;
    int result = 0;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int count = q.size();
        result = max(result,count);
        while(count--){
            Node *temp = q.front();q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    return result;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/maximum-width-of-a-binary-tree/
	struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(8);
    root->right->right->left = newNode(6);
    root->right->right->right = newNode(7);
    cout << "Maximum width is " << maxWidth(root) << endl;
    return 0;
}
