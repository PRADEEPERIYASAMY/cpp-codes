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

int printk(Node *root,int k){
    if(root == nullptr) return 0;
    int l = printk(root->left,k);
    int r = printk(root->right,k);
    if(l == k || r == k) cout<<root->key<<" ";
    return 1+max(l,r);
}

int getMaxSumUtil(Node *root,map<Node*, int>& mp);

int sumofGrandChilderen(Node *root,map<Node*, int>& mp){
    int sum = 0;
    if(root->left) sum+=getMaxSumUtil(root->left->left,mp)+getMaxSumUtil(root->left->right,mp);
    if(root->right) sum+=getMaxSumUtil(root->right->left,mp)+getMaxSumUtil(root->right->right,mp);
    return sum;
}

int getMaxSumUtil(Node *root,map<Node*, int>& mp){
    if(root == nullptr) return 0;
    
    if(mp.find(root) != mp.end()) return mp[root];
    int inc = root->key+sumofGrandChilderen(root,mp); // skip next and move to grandchild
    int exlc = getMaxSumUtil(root->left,mp)+getMaxSumUtil(root->right,mp); // skip current and move to next
    mp[root] = max(inc,exlc);
    return mp[root];
}

int getMaxSum(Node* root){
    if(root == nullptr) return 0;
    map<Node*,int> mp;
    return getMaxSumUtil(root,mp);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->left->left = new Node(1);

    cout << getMaxSum(root) << endl;
    return 0;
}

