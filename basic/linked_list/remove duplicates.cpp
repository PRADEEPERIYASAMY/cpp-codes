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

void RemoveDuplicates(Node *head){
    Node *curr = head;
    while(curr != nullptr && curr->next != nullptr){
        if(curr->data == curr->next->data){
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete(temp);
        }else curr = curr->next;
    }
}

int main() { 
    Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	head->next->next->next=new Node(30);
	head->next->next->next->next=new Node(40);
	printlist(head);
	cout<<endl;
	RemoveDuplicates(head);
	printlist(head);
	return 0;
} 

