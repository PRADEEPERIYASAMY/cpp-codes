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

Node* insertAtPos(Node *head,int pos,int x){
    Node *temp = new Node(x);
    if(pos == 1){
        temp->next = head;
        return temp;
    }
    Node *cur = head;
    for (int i = 1; i <= pos-2 && cur != nullptr ; i++) cur = cur->next;
    if(cur == nullptr) return head;
    temp->next = cur->next;
    cur->next = temp;
    return head;
}

int main() { 
    Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	insertAtPos(head,2,45);
	printlist(head);
	return 0;
} 

