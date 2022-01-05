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

Node* deleteAtPos(Node *head,int pos){
    Node *temp;
    if(pos == 1){
        temp = head->next;
        delete(head);
        return temp;
    }
    Node *cur = head;
    for (int i = 1; i <= pos-2 && cur != nullptr ; i++) cur = cur->next;
    if(cur == nullptr) return head;
    temp = cur->next;
    cur->next = cur->next->next;
    delete(temp);
    return head;
}

int main() {
	Node* head = NULL;
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);
    cout << "Linked list before delete: ";
    printlist(head);
    int x = 3;
    head = deleteAtPos(head, x);
    cout << "\nLinked list after delete: ";
    printlist(head);
    return 0;
}

