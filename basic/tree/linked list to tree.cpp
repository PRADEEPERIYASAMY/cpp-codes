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

struct ListNode{
    int key;
    ListNode* next;
    ListNode(int k){
        key = k;
        next = nullptr;
    }
};

void inorder(Node *root){
    if(root != nullptr){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

Node* convertListToBinary(ListNode *head,Node *root){
    if(head == nullptr){
        root = nullptr;
        return root;
    }
    queue<Node *> q;
    root = new Node(head->key);
    q.push(root);
    head = head->next;
    while(head){
        Node *temp = q.front();
        q.pop();
        temp->left = new Node(head->key);
        q.push(temp->left);
        head = head->next;
        if(head){
            temp->right = new Node(head->key);
            q.push(temp->right);
            head = head->next;
        }
    }
    return root;
}

int main() {
    ListNode *head = new ListNode(10);
    head->next = new ListNode(12);
    head->next->next = new ListNode(15);
    head->next->next->next =new ListNode(25);
    head->next->next->next->next =new ListNode(30);
    head->next->next->next->next->next =new ListNode(36);
    Node *root = convertListToBinary(head,root);
    inorder(root);
    return 0;
}

