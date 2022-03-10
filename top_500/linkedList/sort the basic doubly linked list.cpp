#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
    Node(int data):data(data){
        next = nullptr;
        prev = nullptr;
    }
};

void reverse(Node *&head){
    Node *temp,*current = head;
    while(current != nullptr){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if(temp != nullptr) head = temp->prev;
}

Node *merge(Node *first,Node *second){
    if(!first) return second;
    if(!second) return first;
    if(first->data < second->data){
        first->next = merge(first->next,second);
        first->next->prev = first;
        first->prev = nullptr;
        return first;
    }else{
        second->next = merge(first,second->next);
        second->next->prev = second;
        second->prev = nullptr;
        return second;
    }
}

Node* sort(Node *head){
    if(head == nullptr || head->next == nullptr) return head;
    Node *current = head->next;
    while(current != nullptr){
        if(current->data < current->prev->data) break;
        current = current->next;
    }
    if(current == nullptr) return head;
    current->prev->next = nullptr;
    current->prev = nullptr;
    reverse(current);
    return merge(head,current);
}

void printList(Node *head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void push(Node *&head,int data){
    Node* temp = new Node(data);
    temp->prev = nullptr;
    temp->next = head;
    if(head != nullptr) head->prev = temp;
    head = temp;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/sort-biotonic-doubly-linked-list/
	Node *head = nullptr;
	push(head, 1);
    push(head, 4);
    push(head, 6);
    push(head, 10);
    push(head, 12);
    push(head, 7);
    push(head, 5);
    push(head, 2);
	cout << "Original Doubly linked list:\n";
    printList(head);
    head = sort(head);
    cout << "\nDoubly linked list after sorting:\n";
    printList(head);
    return 0;
}
