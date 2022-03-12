#include <bits/stdc++.h>
using namespace std;

struct tNode {
    int data;
    struct tNode* left;
    struct tNode* right;
};

struct tNode* newtNode(int data){
    struct tNode* node = new tNode;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
  
    return (node);
}

void MorrisTraversal(tNode *root){
    tNode *current,*pre;
    if(root == nullptr) return;
    current = root;
    while(current != nullptr){
        if(current->left == nullptr){
            printf("%d ",current->data);
            current = current->right;
        }else{
            pre = current->left;
            while(pre->right != nullptr && pre->right != current) pre = pre->right;
            if(pre->right == nullptr){
                pre->right = current;
                current = current->left;
            }else{
                pre->right = nullptr;
                printf("%d ",current->data);
                current = current->right;
            }
        }
    }
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/
	struct tNode* root = newtNode(1);
    root->left = newtNode(2);
    root->right = newtNode(3);
    root->left->left = newtNode(4);
    root->left->right = newtNode(5);
    MorrisTraversal(root);
    return 0;
}
