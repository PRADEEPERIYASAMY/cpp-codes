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

Node *insertEnd(Node *head,int x){
    Node *temp = new Node(x);
    if(head == nullptr) return temp;
    Node *curr = head;
    while(curr->next != nullptr) curr = curr->next;
    curr->next = temp;
    return head;
}

int main() { 
	Node *head=NULL;
	head=insertEnd(head,10);
	head=insertEnd(head,20);
	head=insertEnd(head,30);
	printlist(head);
	return 0;
} 

