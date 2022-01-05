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
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }cout<<endl;
}

Node* sortedMerge(Node *a,Node *b){
    if(a == nullptr) return b;
    if(b == nullptr) return a;
    Node *head = nullptr,*tail = nullptr;
    if(a->data<=b->data){
        head = tail = a;a = a->next;
    }else{
        head = tail = b;b = b->next;
    }
    while(a!= nullptr && b!= nullptr){
        if(a->data<=b->data){
            tail->next =a;tail = a;a = a->next;
        }else{
            tail->next = b;tail =b;b = b->next;
        }
    }
    if(a == nullptr)tail->next =b;
    else tail->next = a;
    return head;
}

int main() {
    Node *a=new Node(10);
	a->next=new Node(20);
	a->next->next=new Node(30);
	Node *b=new Node(5);
	b->next=new Node(35);
	printlist(sortedMerge(a,b));
	return 0;
}

