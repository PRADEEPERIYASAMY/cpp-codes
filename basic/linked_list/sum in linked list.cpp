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

int sum(Node *head){
    int sum = 0;
    Node *curr = head;
    while(curr != nullptr){
        sum+=curr->data;
        curr = curr->next;
    }
    return sum;
}

int main() { 
    Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	head->next->next->next=new Node(30);
	head->next->next->next->next=new Node(40);
	printlist(head);
	cout<<endl;
	cout<<sum(head);
	return 0;
}

