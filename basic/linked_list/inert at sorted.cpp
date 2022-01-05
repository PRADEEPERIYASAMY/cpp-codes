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

void printlist(Node *head){
    if(head == nullptr) return;
    cout<<head->data<<" ";
    printlist(head->next);
}

Node* insertAtSorted(Node *head,int x){
    Node *temp = new Node(x);
    if(head == nullptr) return temp;
    Node *curr= head;
    while(curr->next != nullptr && curr->next->data < x) curr = curr->next;
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

int main() {
	Node* head = NULL;
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);
    cout << "Linked list before insertion: ";
    printlist(head);
    int x = 3;
    head = insertAtSorted(head, x);
    cout << "\nLinked list after insertion: ";
    printlist(head);
    return 0;
}

