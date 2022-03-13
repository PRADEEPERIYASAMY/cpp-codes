#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node* nextRight;
    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->nextRight = NULL;
    }
};

void connect(node *root){
    if(root == NULL) return;
    queue<node*> q({root});
    while(!q.empty()){
        int size = q.size();
        node *prev = NULL;
        while(size--){
            node *temp = q.front();q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            if(prev) prev->nextRight = temp;
            prev = temp;
        }
        prev->nextRight = NULL;
    }
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/connect-nodes-at-same-level/
	node* root = new node(10);
    root->left = new node(8);
    root->right = new node(2);
    root->left->left = new node(3);
    connect(root);
    cout << "Following are populated nextRight pointers in the tree"
            " (-1 is printed if there is no nextRight)\n";
    cout << "nextRight of " << root->data << " is "
         << (root->nextRight ? root->nextRight->data : -1) << endl;
    cout << "nextRight of " << root->left->data << " is "
         << (root->left->nextRight ? root->left->nextRight->data : -1) << endl;
    cout << "nextRight of " << root->right->data << " is "
         << (root->right->nextRight ? root->right->nextRight->data : -1) << endl;
    cout << "nextRight of " << root->left->left->data << " is "
    << (root->left->left->nextRight ? root->left->left->nextRight->data : -1) << endl;
    return 0;
}
