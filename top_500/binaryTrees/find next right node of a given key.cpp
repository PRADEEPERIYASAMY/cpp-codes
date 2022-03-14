#include <bits/stdc++.h>
using namespace std;

struct node{
    struct node *left, *right;
    int key;
};

node* newNode(int key){
    node *temp = new node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

node *nextRight(node *root,int k){
    if(root == NULL) return 0;
    queue<node*> qn;
    queue<int> ql;
    int level = 0;
    qn.push(root);
    ql.push(level);
    while(qn.size()){
        node *temp = qn.front();qn.pop();
        level = ql.front();ql.pop();
        if(temp->key == k){
            if(ql.size() == 0 || ql.front() != level) return NULL;
            return qn.front();
        }
        if(temp->left){
            qn.push(temp->left);
            ql.push(level+1);
        }
        if(temp->right){
            qn.push(temp->right);
            ql.push(level+1);
        }
    }
    return NULL;
}

void test(node *root,int k){
    node *nr = nextRight(root,k);
    if(nr) cout<<"Next right of "<<k<<" is "<<nr->key<<"\n";
    else cout<<"No next right node found for "<<k<<"\n";
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/find-next-right-node-of-a-given-key/
	node *root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(6);
    root->right->right = newNode(5);
    root->left->left = newNode(8);
    root->left->right = newNode(4);
    test(root, 10);
    test(root, 2);
    test(root, 6);
    test(root, 5);
    test(root, 8);
    test(root, 4);
    return 0;
}
