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

void printInorder(Node* node){
    if (node == NULL) return;
 
    printInorder(node->left);
    cout << node->key << " ";
    printInorder(node->right);
}

Node* sortedArrayToBST(int arr[],int s,int e){
    if(s>e) return nullptr;
    int mid = (s+e)/2;
    Node *root = new Node(arr[mid]);
    root->left = sortedArrayToBST(arr,s,mid-1);
    root->right = sortedArrayToBST(arr,mid+1,e);
    return root;
}

void storeInorder(Node* node, int inorder[], int &index_ptr){
    if (node == NULL) return;
    storeInorder(node->left, inorder, index_ptr);
    inorder[index_ptr] = node->key;
    index_ptr++;
    storeInorder(node->right, inorder, index_ptr);
}

int *merge(int arr1[], int arr2[], int m, int n){
    int *mergedArr = new int[m + n];
    int i = 0, j = 0, k = 0;

    while (i < m && j < n){
        if (arr1[i] < arr2[j]){
            mergedArr[k] = arr1[i];
            i++;
        }
        else{
            mergedArr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < m){
        mergedArr[k] = arr1[i];
        i++; k++;
    }

    while (j < n){
        mergedArr[k] = arr2[j];
        j++; k++;
    }
    return mergedArr;
}

Node* mergeTrees(Node *root1, Node *root2, int m, int n){

    int arr1[m];
    int i = 0;
    storeInorder(root1, arr1, i);

    int arr2[n];
    int j = 0;
    storeInorder(root2, arr2, j);
    
    int *mergedArr = merge(arr1, arr2, m, n);

    return sortedArrayToBST (mergedArr, 0, m + n - 1);
}

int main(){
    Node *root1 = new Node(100);
    root1->left     = new Node(50);
    root1->right = new Node(300);
    root1->left->left = new Node(20);
    root1->left->right = new Node(70);

    Node *root2 = new Node(80);
    root2->left     = new Node(40);
    root2->right = new Node(120);
 
    Node *mergedTree = mergeTrees(root1, root2, 5, 3);
 
    cout << "Following is Inorder traversal of the merged tree \n";
    printInorder(mergedTree);
    return 0;
}

