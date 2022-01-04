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
    int len = 0;
    for(Node *cur = head;cur != nullptr;cur = cur->next) len++;
    if(len<n) return ;
    Node *cur = head;
    for (int i = 1; i <len-n+1; i++) cur = cur->next;
    cout<<cur->data<<" ";
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

