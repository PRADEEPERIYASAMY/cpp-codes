#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};
 
Node* getNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// approach 1 
// int countSubtreesWithSumXUtil(Node *root,int &count,int x){
//     if(!root) return 0;
//     int ls = countSubtreesWithSumXUtil(root->left,count,x);
//     int rs = countSubtreesWithSumXUtil(root->right,count,x);
//     int sum = ls+rs+root->data;
//     if(sum == x) count++;
//     return sum;
// }

// int countSubtreesWithSumX(Node *root,int x){
//     if(!root) return 0;
//     int count = 0;
//     int ls = countSubtreesWithSumXUtil(root->left,count,x);
//     int rs = countSubtreesWithSumXUtil(root->right,count,x);
//     if(ls+rs+root->data == x) count++;
//     return count;
// }

// approach2 
int countSubtreesWithSumX(Node *root,int x){
    if(!root) return 0;
    static int count = 0;
    static Node* ptr = root;
    int ls = countSubtreesWithSumX(root->left,x);
    int rs = countSubtreesWithSumX(root->right,x);
    int sum = ls+rs+root->data;
    if(sum == x) count++;
    if(ptr != root) return sum;
    else return count;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/count-subtress-sum-given-value-x/
	Node* root = getNode(5);
    root->left = getNode(-10);
    root->right = getNode(3);
    root->left->left = getNode(9);
    root->left->right = getNode(8);
    root->right->left = getNode(-4);
    root->right->right = getNode(7);
    int x = 7;
    cout << "Count = "<< countSubtreesWithSumX(root, x);
    return 0;
}
