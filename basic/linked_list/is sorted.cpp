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

bool isSorted(Node *head){
    if(head == nullptr || head->next == nullptr) return true;
    Node *cur = head;
    while(cur!= nullptr && cur->next != nullptr){
        if(cur->data > cur->next->data) return false;
        cur = cur->next;
    }
    return true;
}

int main() {
	Node* head = NULL;
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);
    printlist(head);
    cout<<endl;
    cout<<isSorted(head);
    return 0;
}

