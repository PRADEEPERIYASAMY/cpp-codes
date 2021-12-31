#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

struct Node{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k){
        key = k;
        left = right = nullptr;
    }
};

void printlist(Node *root){
    Node *temp = root;
    while(temp != nullptr){
        cout<<temp->key<<" ";
        temp = temp->right;
    }
    cout<<endl;
}

void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);    
    }
}  

int postIndex;

Node *cTree(int in[],int post[],int is,int ie){
    if(is>ie) return nullptr;
    Node *root = new Node(post[postIndex--]);
    int inIndex;
    for (int i = is; i <= ie; i++) {
        if(in[i] == root->key){
            inIndex = i;
            break;
        }
    }
    root->right = cTree(in,post,inIndex+1,ie);
    root->left = cTree(in,post,is,inIndex-1);
    return root;
}

int main() {
    int in[]={4 ,8 ,2 ,5 ,1 ,6 ,3 ,7};
	int post[]={8 ,4 ,5 ,2 ,6 ,7 ,3 ,1};
	int n=sizeof(in)/sizeof(in[0]);
	postIndex = n-1;
	Node *root=cTree(in, post, 0, n-1);
	inorder(root);
	
	return 0;
}

