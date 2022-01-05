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

Node* join(Node *head1,Node *head2){
    if(head1 == nullptr && head2 == nullptr) return head1;
    if(head1 == nullptr) return head2;
    if(head2 == nullptr) return head1;
    Node *cur = head1;
    while(cur != nullptr && cur->next != nullptr) cur = cur->next;
    cur->next = head2;
    return head1;
}

int main() {
	Node* head1 = NULL;
    head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(4);
    head1->next->next->next = new Node(5);
    
    Node* head2 = NULL;
    head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(4);
    head2->next->next->next = new Node(5);
    join(head1,head2);
    printlist(head1);
    return 0;
}

