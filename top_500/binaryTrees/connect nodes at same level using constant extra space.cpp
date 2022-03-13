#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node *nextRight;
    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->nextRight = NULL;
    }
};

node *getNextRight(node *p){
    node *temp = p->nextRight;
    while(temp){
        if(temp->left != NULL) return temp->left;
        if(temp->right != NULL) return temp->right;
        temp = temp->nextRight;
    }
    return NULL;
}

// recursive solution
// void connectRecur(node *p){
//     if(!p) return;
//     if(p->nextRight != NULL) connectRecur(p->nextRight);
//     if(p->left){
//         if(p->right){
//             p->left->nextRight = p->right;
//             p->right->nextRight = getNextRight(p);
//         }else p->left->nextRight = getNextRight(p);
//         connectRecur(p->left);
//     }else if(p->right){
//         p->right->nextRight = getNextRight(p);
//         connectRecur(p->right);
//     }else connectRecur(getNextRight(p));
    
// }

// void connect(node *p){
//     p->nextRight = nullptr;
//     connectRecur(p);
// }

// iterative solution
void connect(node *p){
    node *temp;
    if(!p) return ;
    p->nextRight = nullptr;
    while(p){
        node *q = p;
        while(q){
            if(q->left){
                if(q->right) q->left->nextRight = q->right;
                else q->left->nextRight = getNextRight(q);
            }
            if(q->right) q->right->nextRight = getNextRight(q);
            q = q->nextRight;
        }
        if(p->left) p = p->left;
        else if(p->right) p = p->right;
        else p = getNextRight(p);
    }
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/connect-nodes-at-same-level-with-o1-extra-space/
	 node *root = new node(10);
    root->left = new node(8);
    root->right = new node(2);
    root->left->left = new node(3);
    root->right->right     = new node(90);
    connect(root);
    cout << "Following are populated nextRight pointers in the tree (-1 is printed if there is no nextRight) \n";
    cout << "nextRight of " << root->data << " is "<< (root->nextRight? root->nextRight->data: -1) <<endl;
    cout << "nextRight of " << root->left->data << " is "<< (root->left->nextRight? root->left->nextRight->data: -1) << endl;
    cout << "nextRight of " << root->right->data << " is "<< (root->right->nextRight? root->right->nextRight->data: -1) << endl;
    cout << "nextRight of " << root->left->left->data<< " is "<< (root->left->left->nextRight? root->left->left->nextRight->data: -1) << endl;
    cout << "nextRight of " << root->right->right->data << " is "<< (root->right->right->nextRight? root->right->right->nextRight->data: -1) << endl;
    return 0;
}
