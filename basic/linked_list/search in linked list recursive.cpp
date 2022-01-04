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

int search(Node *head,int x){
    if(head == nullptr) return -1;
    if(head->data == x) return 1;
    int res = search(head->next,x);
    if(res == -1) return -1;
    return res+1;
}

int main() { 
	Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	printlist(head);
	cout<<endl;
	cout<<"Position of element in Linked List: "<<search(head,20);
	return 0;
} 

