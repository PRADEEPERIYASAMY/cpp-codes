#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

struct Node  { 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=nullptr;
  }
};

//navie using inorder transversal
void printKth(Node *root, int k,int &count){
    if(root != nullptr){
        printKth(root->left,k,count);
        count++;
        if(count == k){
            cout<<root->key;
            return;
        }
        printKth(root->right,k,count);
    }
}

int main() {
Node *root=new Node(15);
	root->left=new Node(5);
	root->left->left=new Node(3);
	root->right=new Node(20);
	root->right->left=new Node(18);
	root->right->left->left=new Node(16);
	root->right->right=new Node(80);
	int k=3;
	int count=0;
	cout<<"Kth Smallest: ";
	printKth(root,k,count);
	return 0;
}

