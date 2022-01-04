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

Node *delTail(Node *head){
    if(head == nullptr) return nullptr;
    if(head->next == nullptr){
        delete(head);
        return nullptr;
    }
    Node *cur = head;
    while(cur->next->next != nullptr) cur = cur->next;
    delete(cur->next);
    cur->next = nullptr;
    return head;
}

int main() { 
    Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	printlist(head);
	cout<<endl;
	head=delTail(head);
	printlist(head);
	return 0;
}

