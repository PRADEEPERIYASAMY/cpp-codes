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

// using map and recursion
// void getVertical(Node *root,int hd,map<int,vector<int>> &mp){
//     if(root == nullptr) return;
//     mp[hd].push_back(root->key);
//     getVertical(root->left,hd-1,mp);
//     getVertical(root->right,hd+1,mp);
// }

// void verticalOrder(Node *root){
//     map<int,vector<int>> mp;
//     int hd = 0;
//     getVertical(root,hd,mp);
//     for (auto [first,second] : mp) {
//         for (auto &i : second) cout<<i<<" ";
//         cout<<"\n";
//     }
// }

// iteration and map 
void verticalOrder(Node *root){
    if(!root) return;
    unordered_map<int,vector<int>> mp;
    int hd = 0;
    queue<pair<Node*,int>> q({{root,hd}});
    int mi = 0,ma = 0;
    while(!q.empty()){
        auto [first,second] = q.front();q.pop();
        mp[second].push_back(first->key);
        if(first->left) q.push({first->left,second-1});
        if(first->right) q.push({first->right,second+1});
        mi = min(mi,second);
        ma = max(ma,second);
    }
    for (int i = mi; i <= ma; i++) {
        auto tmp = mp[i];
        for (auto &x : tmp) cout<<x<<" ";
        cout<<"\n";
    }
}

// without unoreder map method -- we need to calc mi and ma using recursion then use for loop for each level from mi to ma and traverse the tree for each value of level

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/print-binary-tree-vertical-order-set-2/?ref=lbp
	Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    cout << "Vertical order traversal is \n";
    verticalOrder(root);
    return 0;
}
