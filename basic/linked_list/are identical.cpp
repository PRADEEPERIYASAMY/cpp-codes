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

bool AreIdentical(Node *head1,Node *head2){
    if(head1 == nullptr && head2 == nullptr) return true;
    if(head1 == nullptr) return false;
    if(head2 == nullptr) return false;
    Node *cur1 = head1,*cur2 = head2;
    while(cur1 && cur2){
        if(cur1->data != cur2->data) return false;
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return true;
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
    cout<<AreIdentical(head1,head2);
    return 0;
}

