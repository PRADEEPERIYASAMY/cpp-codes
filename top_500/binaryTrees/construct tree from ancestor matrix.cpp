#include <bits/stdc++.h>
using namespace std;
# define N 6

struct Node{
    int data;
    Node *left, *right;
};
 
struct Node* newNode(int key){
    struct Node* node = new Node;
    node->data = key;
    node->left = node->right = NULL;
    return node;
}

void printInorder(Node* node){
    if (node == NULL) return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

// filled in bottom up manner
Node *ancestorTree(int mat[][N]){
    int parent[N] = {0};
    Node *root = nullptr;
    multimap<int,int> mm;
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = 0; j < N; j++) sum += mat[i][j];
        mm.insert({sum,i});
    }
    Node *node[N];
    for (auto [first,second] : mm) {
        node[second] = newNode(second);
        root = node[second];
        if(first != 0){
            for (int i = 0; i < N; i++) {
                if(!parent[i] && mat[second][i]){
                    if(!node[second]->left) node[second]->left = node[i];
                    else node[second]->right = node[i];
                    parent[i] = 1;
                }
            }
        }
    }
    return root;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/construct-tree-from-ancestor-matrix/
	int mat[N][N] = {{ 0, 0, 0, 0, 0, 0 },
        { 1, 0, 0, 0, 1, 0 },
        { 0, 0, 0, 1, 0, 0 },
        { 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0 },
        { 1, 1, 1, 1, 1, 0 }
    };
    Node* root = ancestorTree(mat);
    cout << "Inorder traversal of tree is \n";
    printInorder(root);
    return 0;
}
