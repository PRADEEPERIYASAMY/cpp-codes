#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left, *right;
};
 
struct Node* newNode(int key){
    struct Node* node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

void printSpecificLevelOrder(Node *root){
    if(root == nullptr) return;
    cout<<root->key;
    
    // since it is perfect height binary tree no need to check right 
    if(root->left != nullptr) cout<<" "<<root->left->key<<" "<<root->right->key;
    if(!root->left->left ) return;
    queue<Node*> q;
    q.push(root->left);
    q.push(root->right);
    Node *first = nullptr,*second = nullptr;
    while(!q.empty()){
        first = q.front();q.pop();second = q.front();q.pop();
        cout<<" "<<first->left->key<<" "<<second->right->key;
        cout<<" "<<first->right->key<<" "<<second->left->key;
        if(first->left->left){
            q.push(first->left);
            q.push(second->right);
            q.push(first->right);
            q.push(second->left);
        }
    }
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/perfect-binary-tree-specific-level-order-traversal/
	
	//Perfect Binary Tree of Height 4
	Node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left  = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left  = newNode(8);
    root->left->left->right  = newNode(9);
    root->left->right->left  = newNode(10);
    root->left->right->right  = newNode(11);
    root->right->left->left  = newNode(12);
    root->right->left->right  = newNode(13);
    root->right->right->left  = newNode(14);
    root->right->right->right  = newNode(15);
    root->left->left->left->left  = newNode(16);
    root->left->left->left->right  = newNode(17);
    root->left->left->right->left  = newNode(18);
    root->left->left->right->right  = newNode(19);
    root->left->right->left->left  = newNode(20);
    root->left->right->left->right  = newNode(21);
    root->left->right->right->left  = newNode(22);
    root->left->right->right->right  = newNode(23);
    root->right->left->left->left  = newNode(24);
    root->right->left->left->right  = newNode(25);
    root->right->left->right->left  = newNode(26);
    root->right->left->right->right  = newNode(27);
    root->right->right->left->left  = newNode(28);
    root->right->right->left->right  = newNode(29);
    root->right->right->right->left  = newNode(30);
    root->right->right->right->right  = newNode(31);
 
    cout << "Specific Level Order traversal of binary tree is \n";
    printSpecificLevelOrder(root);
    return 0;
}
