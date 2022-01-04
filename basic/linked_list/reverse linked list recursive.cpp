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

Node *recRevL(Node *cur,Node *prev){
    if(cur == nullptr) return prev;
    Node *next = cur->next;
    cur->next = prev;
    return recRevL(next,cur);
}

int main() { 
    Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	printlist(head);
	cout<<endl;
	head=recRevL(head,NULL);
	printlist(head);
	return 0;
} 

