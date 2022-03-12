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

Node *constructTreeUtil(int pre[],char preLN[],int &index,int n){
    if(index == n) return nullptr;
    Node *temp = newNode(pre[index]);
    index++;
    if(preLN[index-1] == 'N'){
        temp->left = constructTreeUtil(pre,preLN,index,n);
        temp->right = constructTreeUtil(pre,preLN,index,n);
    }
    return temp;
}

Node *constructTree(int pre[],char preLN[],int n){
    int index = 0;
    return constructTreeUtil(pre,preLN,index,n);
}

void printInorder (struct Node* node){
    if (node == NULL)return;
    printInorder (node->left);
    printf("%d ", node->key);
    printInorder (node->right);
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/perfect-binary-tree-specific-level-order-traversal/
	struct Node *root = NULL;
    int pre[] = {10, 30, 20, 5, 15};
    char preLN[] = {'N', 'N', 'L', 'L', 'L'};
    int n = sizeof(pre)/sizeof(pre[0]);
    root = constructTree (pre, preLN, n);
    printf("Following is Inorder Traversal of the Constructed Binary Tree: \n");
    printInorder (root);
    return 0;
}
