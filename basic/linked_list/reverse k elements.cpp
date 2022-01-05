#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

struct Node{
    Node* next;
    int data;
    Node(int x){
        data = x;
        next = nullptr;
    }
};

void printList(Node* node){
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

void push(Node** head_ref, int new_data){
    Node* new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void rotate(Node **head_ref,int k){
    if(k == 0) return;
    Node* curr = *head_ref;
    int count  =1;
    while(count <k && curr != nullptr){
        curr = curr->next;
        count++;
    }
    if(curr == nullptr) return;
    Node *kthNode = curr;
    while(curr->next != nullptr) curr = curr->next;
    curr->next = *head_ref;
    *head_ref = kthNode->next;
    kthNode->next = nullptr;
}

// can also be done by joining tail and head
int main() {
	Node* head = NULL;
    for (int i = 60; i > 0; i -= 10) push(&head, i);
    cout << "Given linked list \n";
    printList(head);
    rotate(&head, 4);
    cout << "\nRotated Linked list \n";
    printList(head);
    return (0);
}

