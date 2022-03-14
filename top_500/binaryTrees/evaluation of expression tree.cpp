#include <bits/stdc++.h>
using namespace std;

class node{
public:
    string info;
    node *left = NULL, *right = NULL;
    node(string x){
        info = x;
    }
};

int eval(node *root){
    if(!root) return 0;
    if(!root->left && !root->right) return atoi(root->info.c_str());
    int lval = eval(root->left);
    int rval = eval(root->right);
    if(root->info == "+") return lval+rval;
    if(root->info == "-") return lval - rval;
    if(root->info == "*") return lval*rval;
    return lval/rval;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/evaluation-of-expression-tree/?ref=lbp
	 node *root = new node("+");
    root->left = new node("*");
    root->left->left = new node("5");
    root->left->right = new node("-4");
    root->right = new node("-");
    root->right->left = new node("100");
    root->right->right = new node("20");
    cout << eval(root) << endl;
 
    delete(root);
 
    root = new node("+");
    root->left = new node("*");
    root->left->left = new node("5");
    root->left->right = new node("4");
    root->right = new node("-");
    root->right->left = new node("100");
    root->right->right = new node("/");
    root->right->right->left = new node("20");
    root->right->right->right = new node("2");
 
    cout << eval(root);
    return 0;
}

