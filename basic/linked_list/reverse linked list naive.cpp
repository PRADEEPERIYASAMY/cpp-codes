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

Node *revList(Node *head){
    vector<int> arr;
    for(Node *cur = head;cur != nullptr;cur=cur->next) arr.push_back(cur->data);
    for(Node *cur = head;cur != nullptr;cur=cur->next){
        cur->data = arr.back();
        arr.pop_back();
    }
    return head;
}

int main() { 
    Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	printlist(head);
	cout<<endl;
	head=revList(head);
	printlist(head);
	return 0;
} 

