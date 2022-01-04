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

Node* delHead(Node *head){
    if(head ==nullptr) return nullptr;
    Node *temp = head->next;
    delete(head);
    return temp;
} 

int main() { 
	Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	printlist(head);
	cout<<endl;
	head=delHead(head);
	printlist(head);
	return 0;
} 

