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

void printNthFromEnd(Node *head,int n){
    if(head == nullptr) return;
    Node *first = head;
    for (int i = 0; i <n; i++) {
        if(first == nullptr) return;
        first = first->next;
    }
    Node *second = head;
    while(first != nullptr){
        second = second->next;
        first = first->next;
    }
    cout<<second->data;
}

int main() { 
    Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	head->next->next->next=new Node(40);
	head->next->next->next->next=new Node(50);
	printlist(head);
	cout<<"Nth node from end of Linked List: ";
	printNthFromEnd(head,2);
	return 0;
} 

