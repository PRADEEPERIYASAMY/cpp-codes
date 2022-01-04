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

void printMiddle(Node * head){
    if(head==NULL)return;
    int count=0;
    Node *curr;
    for(curr=head;curr!=NULL;curr=curr->next)count++;
    curr=head;
    for(int i=0;i<count/2;i++)curr=curr->next;
    cout<<curr->data;
}

int main() { 
    Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	head->next->next->next=new Node(40);
	head->next->next->next->next=new Node(50);
	printlist(head);
	cout<<endl;
	cout<<"Middle of Linked List: ";
	printMiddle(head);
	return 0;
} 

