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

Node* sortedInsert(Node *head,int x){
    Node *temp = new Node(x);
    if(head == nullptr) return temp;
    if(x < head->data){
        temp->next = head;
        return temp;
    }
    Node *cur = head;
    while(cur->next != nullptr && cur->next->data <x) cur = cur->next;
    temp->next = cur->next;
    cur->next = temp;
    return head;
}

int main() { 
    Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	sortedInsert(head,45);
	printlist(head);
	return 0;
}

