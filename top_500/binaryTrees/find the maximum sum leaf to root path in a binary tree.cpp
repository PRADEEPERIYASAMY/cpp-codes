#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
};

node* newNode(int data){
    node* temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

bool printPath(node *root,node *leafNode){
    if(root == NULL) return false;
    bool ls = printPath(root->left,leafNode);
    bool rs = printPath(root->right,leafNode);
    if(root == leafNode || ls || rs){
        cout<<root->data<<" ";
        return true;
    }
    return false;
}

void getTargetLeaf(node *root,int &maxSum,int currSum,node *&leafNode){
    if(!root) return;
    currSum = currSum+root->data;
    if(!root->left && !root->right){
        if(currSum>maxSum){
            maxSum = currSum;
            leafNode = root;
        }
    }
    getTargetLeaf(root->left,maxSum,currSum,leafNode);
    getTargetLeaf(root->right,maxSum,currSum,leafNode);
}

int maxSumPath(node *root){
    if(root == NULL) return 0;
    node *leafNode;
    int maxSum = INT_MIN;
    getTargetLeaf(root,maxSum,0,leafNode);
    printPath(root,leafNode);
    return maxSum;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/find-the-maximum-sum-path-in-a-binary-tree/
	node* root = NULL;
    root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(7);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
    cout << "Following are the nodes on the maximum sum path \n";
    int sum = maxSumPath(root);
    cout << "\nSum of the nodes is " << sum;
    return 0;
}
