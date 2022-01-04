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

void minMax(Node *head){
    int ma = INT_MIN,mi = INT_MAX;
    Node *curr = head;
    while(curr != nullptr){
        mi = min(mi,curr->data);
        ma = max(ma,curr->data);
        curr = curr->next;
    }
    cout<<mi<<" "<<ma;
}

int main() { 
    Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	head->next->next->next=new Node(30);
	head->next->next->next->next=new Node(40);
	printlist(head);
	cout<<endl;
	minMax(head);
	return 0;
} 

